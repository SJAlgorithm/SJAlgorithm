//package com.bs.lec18.member.controller;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while((t--)>0){
            int n=sc.nextInt();
            int k=sc.nextInt();
            int[] time=new int[n+1];
            int[] cost=new int[n+1];
            int[] indeg=new int[n+1];
            //make graph
            ArrayList<ArrayList<Integer>> v=new ArrayList<>();
            for(int i=0;i<=n;i++) v.add(new ArrayList<>());
            for(int i=1;i<=n;i++){
                time[i]=sc.nextInt();
                cost[i]=time[i];
            }
            for(int i=0;i<k;i++){
                int a=sc.nextInt();
                int b=sc.nextInt();
                v.get(a).add(b);
                indeg[b]++;
            }

            int w=sc.nextInt();
            Queue<Integer> queue=new LinkedList<>();
            for(int i=1;i<=n;i++){
                if(indeg[i]==0) {
                    queue.offer(i);
                }
            }
            while(!queue.isEmpty()){
                int now=queue.poll();

                if(now==w){
                    System.out.println(cost[now]);
                    break;
                }

                for(int i=0;i<v.get(now).size();i++){
                    int next=v.get(now).get(i);
                    indeg[next]--;

                    cost[next]=Math.max(cost[next],time[next]+cost[now]);

                    if(indeg[next]==0){
                        queue.offer(next);
                    }
                }
            }
        }
    }
}

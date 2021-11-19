import java.util.*;
class Solution {
    static boolean visited[]=new boolean[200];
    public void bfs(int node,int n,int[][] computers){
        Queue<Integer> q=new LinkedList<Integer>();
        q.offer(node);
        visited[node]=true;
        
        while(!q.isEmpty()){
            int now=q.poll();
            
            for(int i=0;i<n;i++){
                if(i!=now && computers[now][i]==1 && !visited[i]){
                    q.offer(i);
                    visited[i]=true;
                }
            }
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,n,computers);
                answer++;
            }
        }
        return answer;
    }
}

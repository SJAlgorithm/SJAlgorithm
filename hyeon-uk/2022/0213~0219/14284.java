import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node implements Comparable<Node> {
    int to;
    int cost;
    public Node(int to,int cost){
        this.to=to;
        this.cost=cost;
    }

    @Override
    public int compareTo(Node node){
        return this.cost-node.cost;
    }
}

public class P14284 {
    public static int n,m,a,b,c,start,end;
    public static ArrayList<ArrayList<Node>> graph=new ArrayList<>();

    public static long dijk(){
        int dist[]=new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        PriorityQueue<Node> pq=new PriorityQueue<>();

        pq.offer(new Node(start,0));
        dist[start]=0;
        while(!pq.isEmpty()){
            Node node=pq.poll();
            int now=node.to;
            int cost=node.cost;

            if(cost>dist[now]) continue;
            if(now==end){
                return cost;
            }
            for(Node nextNode:graph.get(now)){
                int next=nextNode.to;
                int next_cost=nextNode.cost;

                if(dist[next]>cost+next_cost){
                    dist[next]=cost+next_cost;
                    pq.offer(new Node(next,cost+next_cost));
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        for(int i=0;i<=n;i++) graph.add(new ArrayList<>());
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine()," ");
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            c=Integer.parseInt(st.nextToken());

            graph.get(a).add(new Node(b,c));
            graph.get(b).add(new Node(a,c));
        }

        st=new StringTokenizer(br.readLine()," ");
        start=Integer.parseInt(st.nextToken());
        end=Integer.parseInt(st.nextToken());

        System.out.println(dijk());
    }
}

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Queue;
class Solution {
    static int[] dist;
    ArrayList<ArrayList<Integer>> graph;
    
    public void init(int n,int [][] edge){
        graph=new ArrayList<ArrayList<Integer>>();
        dist=new int[n+1];
        for(int i=0;i<n+1;i++){
            graph.add(new ArrayList<Integer>());
            dist[i]=-1;
        }
        dist[1]=0;
        for(int i=0;i<edge.length;i++){
            int a=edge[i][0];
            int b=edge[i][1];
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
    }
    
    public int bfs(){
        Queue<Integer> q=new LinkedList<>();
        q.offer(1);
        int max_value=-1;
        while(!q.isEmpty()){
            int now=q.poll();
            int now_dist=dist[now];
            max_value=Math.max(max_value,now_dist);
            
            for(int i=0;i<graph.get(now).size();i++){
                int next=graph.get(now).get(i);
                if(dist[next]==-1||now_dist+1<dist[next]){
                    dist[next]=now_dist+1;
                    q.offer(next);
                }
            }
        }
        return max_value;
    }
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        init(n,edge);
        int max_dist=bfs();
        for(int i=1;i<=n;i++){
            if(dist[i]==max_dist) answer++;
        }
        return answer;
    }
}

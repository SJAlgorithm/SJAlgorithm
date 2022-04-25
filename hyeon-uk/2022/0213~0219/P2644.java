import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class P2644 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n,m,a,b;
        ArrayList<ArrayList<Integer>> graph=new ArrayList<>();
        Queue<Integer> q=new LinkedList<>();
        int dist[];
        boolean visited[];

        n=Integer.parseInt(br.readLine());
        st=new StringTokenizer(br.readLine()," ");
        a=Integer.parseInt(st.nextToken());
        b=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(br.readLine());

        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }
        dist=new int[n+1];
        visited=new boolean[n+1];

        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine()," ");
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        q.offer(a);
        visited[a]=true;
        while(!q.isEmpty()){
            int now=q.poll();

            if(now==b) break;

            for(int next:graph.get(now)){
                if(!visited[next]){
                    visited[next]=true;
                    dist[next]=dist[now]+1;
                    q.offer(next);
                }
            }
        }

        if(dist[b]==0){
            System.out.println(-1);
        }
        else{
            System.out.println(dist[b]);
        }
    }
}

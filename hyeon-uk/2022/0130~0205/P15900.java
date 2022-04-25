import java.io.*;
import java.util.*;



public class P15900 {
    public static ArrayList<ArrayList<Integer>> graph=new ArrayList<>();
    public static int n;
    public static boolean visited[];
    public static int dist[];
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");

        n=Integer.parseInt(st.nextToken());

        visited=new boolean[n+1];
        dist=new int[n+1];

        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }

        for(int i=0;i<n-1;i++){
            st=new StringTokenizer(br.readLine()," ");
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        Queue<Integer> queue=new LinkedList<>();
        visited[1]=true;
        dist[1]=0;
        queue.offer(1);

        int sum=0;

        while(!queue.isEmpty()){
            int now=queue.poll();
            boolean isLeaf=true;
            for(int i=0;i<graph.get(now).size();i++){
                int next=graph.get(now).get(i);
                if(!visited[next]){
                    visited[next]=true;
                    dist[next]=dist[now]+1;
                    queue.offer(next);
                    isLeaf=false;
                }
            }
            if(isLeaf){
                sum+=dist[now];
            }
        }

        if(sum%2==1){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }
}

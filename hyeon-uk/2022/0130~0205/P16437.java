import java.io.*;
import java.util.*;



public class P16437 {
    public static ArrayList<ArrayList<Integer>> graph=new ArrayList<>();
    public static int n;
    public static int wolf[];
    public static int sheep[];

    public static long dfs(int now){
        //leaf node
        if(graph.get(now).size()==0){
            return sheep[now];
        }

        int nowSheep=sheep[now];
        long childSheep=0;
        for(int i=0;i<graph.get(now).size();i++){
            int next=graph.get(now).get(i);
            childSheep+=dfs(next);
        }

        //올라오다 늑대한테 먹히고 남은 양의수
        long aliveSheep=nowSheep+childSheep-wolf[now];
        if(aliveSheep<0) aliveSheep=0;
        return aliveSheep;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");

        n=Integer.parseInt(st.nextToken());
        wolf=new int[n+1];
        sheep=new int[n+1];

        for(int i=0;i<=n;i++) graph.add(new ArrayList<>());

        for(int i=2;i<=n;i++){
            st=new StringTokenizer(br.readLine()," ");

            String op=st.nextToken();
            int w=Integer.parseInt(st.nextToken());
            int parent= Integer.parseInt(st.nextToken());

            if(op.equals("S")){
                sheep[i]=w;
            }
            else{
                wolf[i]=w;
            }
            graph.get(parent).add(i);
        }

        System.out.println(dfs(1));
    }
}

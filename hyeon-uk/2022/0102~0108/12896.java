import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> arr;
    static boolean visited[];
    static int far=0,farNode=0;

    public static void setFalse(){
        Arrays.fill(visited,false);
    }

    public static void dfs(int node,int dist){
        if(visited[node]) return;
        visited[node]=true;

        if(far<dist){
            far=dist;
            farNode=node;
        }

        for(int i=0;i<arr.get(node).size();i++){
            int next=arr.get(node).get(i);
            dfs(next,dist+1);
        }
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();
        //make graph
        arr=new ArrayList<>();
        for(int i=0;i<=n;i++) arr.add(new ArrayList<>());
        for(int i=0;i<n-1;i++){
            int u=sc.nextInt();
            int v=sc.nextInt();
            arr.get(u).add(v);
            arr.get(v).add(u);
        }


        //make array
        visited=new boolean[n+1];

        dfs(1,0);

        far=0;
        setFalse();
        dfs(farNode,0);

        System.out.println((far+1)/2);
    }
}

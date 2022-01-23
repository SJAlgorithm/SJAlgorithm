import java.util.ArrayList;
import java.util.Scanner;

public class BJ12896 {

    static int n;
    static int max;
    static int node;
    static ArrayList<Node>[] list;
    static boolean[] visited;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        list = new ArrayList[n + 1];
        for(int i=0; i<n+1;i++){
            list[i] = new ArrayList<>();
        }
        for(int i=0;i<n-1;i++){
            int s = sc.nextInt();
            int e = sc.nextInt();
            list[s].add(new Node(e, 1));
            list[e].add(new Node(s, 1));
        }
        max = -1;
        visited = new boolean[n + 1];
        dfs(1, 0);

        max = -1;
        visited = new boolean[n + 1];
        dfs(node, 0);
        System.out.println((1+max)/2);
    }

    public static void dfs(int x, int len){
        if(max < len){
            max = len;
            node = x;
        }
        visited[x] = true;

        for(int i=0; i<list[x].size(); i++){
            Node next = list[x].get(i);
            if(!visited[next.end]){
                dfs(next.end, len+next.cost);
                visited[x]=true;
            }
        }
    }

}

class Node{
    int end;
    int cost;
    public Node(int x, int y){
        this.end = x;
        this.cost = y;
    }
}
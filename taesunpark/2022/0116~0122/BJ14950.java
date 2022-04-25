import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BJ14950 {

    static class Edge{
        int h, tg, w;
        public Edge(int home, int target, int weight){
            h=home;
            tg=target;
            w=weight;
        }
    }

    static int n,m,t;
    static List<Edge> list = new ArrayList<>();
    static int[] parent = new int[10001];

    static int getParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }
    static boolean findParent(int a, int b){
        a = getParent(a);
        b = getParent(b);
        return a==b;
    }
    static void union(int a, int b){
        a = getParent(a);
        b = getParent(b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());

        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int tg = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            list.add(new Edge(h, tg, w));
            list.add(new Edge(tg, h, w));
        }

        list.sort((a, b)->a.w - b.w);

        int sum =0, cnt =0;
        for(Edge e : list){
            if(!findParent(e.h, e.tg)){
                sum += e.w + (t * cnt++);
                union(e.h, e.tg);
            }
        }
        System.out.println(sum);



    }
}

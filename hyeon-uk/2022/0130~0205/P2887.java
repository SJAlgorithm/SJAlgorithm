import java.io.*;
import java.util.*;

class Node{
    int number;
    int x,y,z;
    public Node(int number,int x,int y,int z){
        this.number=number;
        this.x=x;
        this.y=y;
        this.z=z;
    }
}

class CNode{
    int dist;
    int u,v;
    public CNode(int dist,int u,int v){
        this.dist=dist;
        this.u=u;
        this.v=v;
    }
}

public class P2887{
    public static List<Node> xList=new ArrayList<>();
    public static List<Node> yList=new ArrayList<>();
    public static List<Node> zList=new ArrayList<>();
    public static List<CNode> totalList=new ArrayList<>();

    public static int[] parent;
    public static int find(int p){
        if(parent[p]==p){
            return p;
        }
        else{
            return find(parent[p]);
        }
    }

    public static void unionParent(int a,int b){
        a=find(a);
        b=find(b);

        if(a<b){
            parent[b]=a;
        }
        else{
            parent[a]=b;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");

        int n=Integer.parseInt(st.nextToken());

        for(int i=1;i<=n;i++){
            st=new StringTokenizer(br.readLine()," ");
            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            int z=Integer.parseInt(st.nextToken());

            Node node=new Node(i,x,y,z);
            xList.add(node);
            yList.add(node);
            zList.add(node);
        }

        xList.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.x-o2.x;
            }
        });

        for(int i=0;i<n-1;i++){
            int dist=xList.get(i+1).x-xList.get(i).x;
            CNode node=new CNode(dist,xList.get(i).number,xList.get(i+1).number);
            totalList.add(node);
        }

        yList.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.y-o2.y;
            }
        });

        for(int i=0;i<n-1;i++){
            int dist=yList.get(i+1).y-yList.get(i).y;
            CNode node=new CNode(dist,yList.get(i).number,yList.get(i+1).number);
            totalList.add(node);
        }

        zList.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.z-o2.z;
            }
        });

        for(int i=0;i<n-1;i++){
            int dist=zList.get(i+1).z-zList.get(i).z;
            CNode node=new CNode(dist,zList.get(i).number,zList.get(i+1).number);
            totalList.add(node);
        }

        totalList.sort(new Comparator<CNode>() {
            @Override
            public int compare(CNode o1, CNode o2) {
                return o1.dist-o2.dist;
            }
        });

        long sum=0;
        parent=new int[n+1];
        for(int i=1;i<=n;i++) parent[i]=i;
        for(int i=0;i<totalList.size();i++){
            CNode e=totalList.get(i);
            int u=e.u;
            int v=e.v;
            int dist=e.dist;

            if(find(u)==find(v)) continue;

            unionParent(u,v);

            sum+=dist;
        };
        System.out.println(sum);
    }
}
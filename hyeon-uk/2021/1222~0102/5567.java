import java.util.*;

class Node{
    int sNum;
    int depth;
    public Node(int sNum,int depth){
        this.sNum=sNum;
        this.depth=depth;
    }

    public int getsNum() {
        return sNum;
    }

    public void setsNum(int sNum) {
        this.sNum = sNum;
    }

    public int getDepth() {
        return depth;
    }

    public void setDepth(int depth) {
        this.depth = depth;
    }
}
public class Main {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();

        ArrayList<ArrayList<Integer>> v=new ArrayList<>();
        for(int i=0;i<=n;i++) v.add(new ArrayList<>());

        for(int i=0;i<m;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            v.get(a).add(b);
            v.get(b).add(a);
        }

        int result=0;
        Queue<Node> queue=new LinkedList<>();
        boolean[] visited=new boolean[n+1];

        queue.offer(new Node(1,0));
        visited[1]=true;
        while(!queue.isEmpty()){
            Node now=queue.poll();
            int sNum=now.getsNum();
            int depth=now.getDepth();
            if(depth>=3) continue;
            result++;
            for(int i=0;i<v.get(sNum).size();i++){
                int next=v.get(sNum).get(i);
                if(!visited[next]){
                    queue.offer(new Node(next,depth+1));
                    visited[next]=true;
                }
            }
        }
        System.out.println(result-1);
    }
}

import java.util.*;

class Node{
    int left,right;

    public Node(int left, int right) {
        this.left = left;
        this.right = right;
    }

    public int getLeft() {
        return left;
    }

    public void setLeft(int left) {
        this.left = left;
    }

    public int getRight() {
        return right;
    }

    public void setRight(int right) {
        this.right = right;
    }
}

public class Main {
    static boolean check(Node prev,Node now){
        if(now.getLeft()<=prev.getRight()&&now.getRight()>=prev.getRight()){
            return false;
        }
        return true;
    }
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        ArrayList<Node> v=new ArrayList<>();
        for(int i=0;i<n;i++){
            int x= scanner.nextInt();
            int r= scanner.nextInt();;
            v.add(new Node(x-r,x+r));
        }
        Collections.sort(v, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(o1.getLeft()!=o2.getLeft()){
                    return o1.getLeft()-o2.getLeft();
                }
                else{
                    return o1.getRight()-o2.getRight();
                }
            }
        });
        boolean result=true;
        for(int i=1;i<n;i++){
            if(!check(v.get(i-1),v.get(i))){
                result=false;
                break;
            }
        }
        System.out.println(result?"YES":"NO");
    }
}

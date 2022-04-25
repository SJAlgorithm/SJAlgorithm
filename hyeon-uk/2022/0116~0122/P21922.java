import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

class Node{
    Point p;
    int d;
    public Node(Point p,int d){
        this.p=p;
        this.d=d;
    }
}

class Point{
    int x,y;
    public Point(int x,int y){
        this.x=x;
        this.y=y;
    }
}

public class P21922 {
    public static int n,m,result=0;
    public static int maze[][];
    public static boolean visited[][][];
    //위쪽부터 시계방향
    public static int mx[]=new int[]{-1,0,1,0};
    public static int my[]=new int[]{0,1,0,-1};
    public static Queue<Node> q=new LinkedList<>();

    public static boolean isIn(Point p){
        return 0<=p.x&&p.x<n&&0<=p.y&&p.y<m;
    }

    public static Node move(Point p,int d){
        if(maze[p.x][p.y]==1){
            if(d==1||d==3) d=(d+2)%4;
        } else if(maze[p.x][p.y]==2){
            if(d==0||d==2) d=(d+2)%4;
        }else if(maze[p.x][p.y]==3){
            if(d==0 || d==2){
                d++;
            }
            else{
                d--;
            }
        }else if(maze[p.x][p.y]==3||maze[p.x][p.y]==4){
            if(d==0 || d==2){
                d = (d-1<0) ? 3 : d-1;
            }
            else{
                d=(d+1)%4;
            }
        }
        int nx=p.x+mx[d];
        int ny=p.y+my[d];
        return new Node(new Point(nx,ny),d);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        maze=new int[n][m];
        visited=new boolean[n][m][4];

        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                maze[i][j]=Integer.parseInt(st.nextToken());
                if(maze[i][j]==9){
                    for(int d=0;d<4;d++){
                        q.add(new Node(new Point(i,j),d));
                        visited[i][j][d]=true;
                    }
                }
            }
        }

        while(!q.isEmpty()){
            Node now=q.poll();
            Point p=now.p;
            int d=now.d;

            Node next=move(p,d);
            if(isIn(next.p)&&!visited[next.p.x][next.p.y][next.d]){
                q.add(next);
                visited[next.p.x][next.p.y][next.d]=true;
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result+=(visited[i][j][0]||visited[i][j][1]
                        ||visited[i][j][2]||visited[i][j][3] ? 1: 0);
            }
        }

        System.out.println(result);


    }
}
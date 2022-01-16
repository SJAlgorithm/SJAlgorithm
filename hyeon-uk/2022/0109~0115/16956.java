import java.util.*;

class Point{
    int x,y;
    public Point(int x,int y){
        this.x=x;
        this.y=y;
    }
}

public class Main {
    static char maze[][];
    static Point mv[]=new Point[]{new Point(1,0),new Point(-1,0),new Point(0,1),new Point(0,-1)};
    static int r,c;
    public static boolean isIn(int x,int y){
        return 0<=x&&x<r&&0<=y&&y<c;
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        r=sc.nextInt();
        c=sc.nextInt();
        Queue<Point> queue=new LinkedList<>();
        maze=new char[r][c];
        for(int i=0;i<r;i++){
            String temp=sc.next();
            for(int j=0;j<c;j++){
                maze[i][j]=temp.charAt(j);
                if(maze[i][j]=='W') queue.offer(new Point(i,j));
            }
        }

        while(!queue.isEmpty()){
            Point w=queue.poll();
            for(int i=0;i<4;i++){
                int nx=w.x+mv[i].x;
                int ny=w.y+mv[i].y;

                if(isIn(nx,ny)){
                    if(maze[nx][ny]=='S'){
                        System.out.println(0);
                        return;
                    }
                    else if(maze[nx][ny]=='.'){
                        maze[nx][ny]='D';
                    }
                }
            }
        }
        System.out.println(1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                System.out.print(maze[i][j]);
            }
            System.out.println();
        }

    }
}

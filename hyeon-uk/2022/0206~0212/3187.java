import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Point{
    int x,y;
    public Point(int x,int y){
        this.x=x;
        this.y=y;
    }
}

public class P3187 {
    public static char[][] maze;
    public static boolean[][] visited;
    public static int[][] mv=new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
    public static int r,c;
    public static int sheep=0;
    public static int wolf=0;

    public static boolean isIn(int x,int y){
        return 0<=x&&x<r&&0<=y&&y<c;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");

        r=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());

        maze=new char[r][c];
        visited=new boolean[r][c];

        for(int i=0;i<r;i++){
            String temp=br.readLine();
            for(int j=0;j<c;j++){
                maze[i][j]=temp.charAt(j);
            }
        }

        Queue<Point> queue=new LinkedList<>();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(maze[i][j]!='#'&&!visited[i][j]){
                    visited[i][j]=true;
                    queue.offer(new Point(i,j));
                    int tSheep=0;
                    int tWolf=0;
                    while(!queue.isEmpty()){
                        Point now=queue.poll();

                        if(maze[now.x][now.y]=='v') tWolf++;
                        else if(maze[now.x][now.y]=='k') tSheep++;

                        for(int d=0;d<4;d++){
                            int nx=now.x+mv[d][0];
                            int ny=now.y+mv[d][1];

                            if(isIn(nx,ny)&&!visited[nx][ny]&&maze[nx][ny]!='#'){
                                queue.offer(new Point(nx,ny));
                                visited[nx][ny]=true;
                            }
                        }
                    }
                    if(tWolf>=tSheep){
                        wolf+=tWolf;
                    }
                    else{
                        sheep+=tSheep;
                    }
                }
            }
        }
        System.out.println(sheep+" "+wolf);
    }
}

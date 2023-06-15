import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static char maze[][]=new char[15][15];
    public static int ret=1;
    public static int n,m;
    public static int mv[][]=new int[][]{{1,0},{-1,0},{0,1},{0,-1}};

    public static boolean isIn(int x,int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }

    public static void removeCross(int x,int y,int len){
        for(int d=0;d<4;d++){
            for(int l=1;l<=len;l++){
                int nx=x+mv[d][0]*l;
                int ny=y+mv[d][1]*l;
                maze[nx][ny]='.';
            }
        }
        maze[x][y]='.';
    }
    public static void paintCross(int x,int y,int len){
        for(int d=0;d<4;d++){
            for(int l=1;l<=len;l++){
                int nx=x+mv[d][0]*l;
                int ny=y+mv[d][1]*l;
                maze[nx][ny]='#';
            }
        }
        maze[x][y]='#';
    }

    public static boolean isCross(int x,int y,int len){
        boolean flag=true;
        for(int d=0;d<4;d++){
            for(int l=1;l<=len;l++){
                int nx=x+mv[d][0]*l;
                int ny=y+mv[d][1]*l;

                if(isIn(nx,ny)&&maze[nx][ny]=='#'){
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        return flag;
    }

    public static void trace(int score,int cnt){
        if(cnt==2){
            ret=Math.max(score,ret);
            return;
        }
        boolean flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='#'){
                    int len=0;
                    while(isCross(i,j,len)){
                        removeCross(i,j,len);
                        trace(score*(4*len+1),cnt+1);
                        paintCross(i,j,len);
                        len++;
                        flag=true;
                    }
                }
            }
        }
        if(!flag) return;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine(), " ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++){
            String str=br.readLine();
            for(int j=0;j<m;j++){
                maze[i][j]=str.charAt(j);
            }
        }
        trace(1,0);
        System.out.println(ret);

    }
}

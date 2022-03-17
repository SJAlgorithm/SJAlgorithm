import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class P20056 {
    public static ArrayList<FireBall> maze[][];
    public static ArrayList<FireBall> fireBalls;
    public static int n,m,k;
    public static int mr[]=new int[]{-1,-1,0,1,1,1,0,-1};
    public static int mc[]=new int[]{0,1,1,1,0,-1,-1,-1};

    static class FireBall{
        int r,c,m,s,d;

        public FireBall(int r, int c, int m, int s, int d) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.s = s;
            this.d = d;
        }
    }

    public static void fireBallMove(){
        for(FireBall fireBall:fireBalls){

            int nr = (n+fireBall.r + (fireBall.s%n) * mr[fireBall.d])%n;
            int nc = (n+fireBall.c + (fireBall.s%n) * mc[fireBall.d])%n;

            fireBall.r=nr;
            fireBall.c=nc;

            maze[fireBall.r][fireBall.c].add(fireBall);
        }
    }

    public static void dividFireBalls(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j].size()>=2){
                    boolean flag=true;
                    int mSum=0;
                    int sSum=0;

                    boolean even=true;
                    for(int d=0;d<maze[i][j].size();d++){
                        if(maze[i][j].get(d).d%2!=0) {
                            even=false;
                            break;
                        }
                    }

                    boolean odd=true;
                    for(int d=0;d<maze[i][j].size();d++){
                        if(maze[i][j].get(d).d%2==0){
                            odd=false;
                            break;
                        }
                    }

                    flag=even|odd;

                    for(FireBall f:maze[i][j]){
                        mSum+=f.m;
                        sSum+=f.s;
                        fireBalls.remove(f);
                    }
                    mSum/=5;
                    sSum/=maze[i][j].size();
                    if(mSum!=0){
                        if(flag) {
                            for(int d=0;d<=6;d+=2) {
                                fireBalls.add(new FireBall(i, j, mSum , sSum, d));
                            }
                        }
                        else{
                            for(int d=1;d<=7;d+=2){
                                fireBalls.add(new FireBall(i, j, mSum, sSum, d));
                            }
                        }
                    }
                }
                maze[i][j].clear();
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        k=Integer.parseInt(st.nextToken());

        maze=new ArrayList[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maze[i][j]=new ArrayList<>();
            }
        }
        fireBalls=new ArrayList<>();

        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine()," ");
            int r=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());
            int dm=Integer.parseInt(st.nextToken());
            int ds=Integer.parseInt(st.nextToken());
            int dd=Integer.parseInt(st.nextToken());
            fireBalls.add(new FireBall(r,c,dm,ds,dd));
        }

        for(int i=0;i<k;i++){
            fireBallMove();
            dividFireBalls();
        }
        int ret=0;
        for(FireBall f:fireBalls){
            ret+=f.m;
        }
        System.out.println(ret);
    }

}

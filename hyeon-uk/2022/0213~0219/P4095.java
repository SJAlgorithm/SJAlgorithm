import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class P4095 {
    public static int maze[][]=new int[1000][1000];
    public static int dp[][]=new int[1000][1000];
    public static int n,m,ret;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while(true){
            st=new StringTokenizer(br.readLine()," ");
            n=Integer.parseInt(st.nextToken());
            m=Integer.parseInt(st.nextToken());

            if(n==0&&m==0) break;

            for(int i=0;i<n;i++){
                Arrays.fill(dp[i],0);
                st=new StringTokenizer(br.readLine()," ");
                for(int j=0;j<m;j++){
                    maze[i][j]=Integer.parseInt(st.nextToken());
                }
            }

            //가로 세로 초기화
            for(int i=0;i<m;i++){
                if(maze[0][i]==1) dp[0][i]=1;
                if(maze[i][0]==1) dp[i][0]=1;
            }
            ret=0;

            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(maze[i][j]==1) {
                        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;

                    }
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ret=Math.max(ret,dp[i][j]);
                }
            }
            System.out.println(ret);
        }
    }
}

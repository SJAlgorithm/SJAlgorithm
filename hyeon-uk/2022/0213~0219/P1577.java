import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P1577 {
    public static boolean visited[][]=new boolean[202][202];
    public static long dp[][]=new long[101][101];

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        int m=Integer.parseInt(st.nextToken());//가로
        int n=Integer.parseInt(st.nextToken());//세로

        int k=Integer.parseInt(br.readLine());

        for(int i=0;i<k;i++){
            st=new StringTokenizer(br.readLine()," ");
            int a=Integer.parseInt(st.nextToken());//가로
            int b=Integer.parseInt(st.nextToken());//세로
            int c=Integer.parseInt(st.nextToken());//가로
            int d=Integer.parseInt(st.nextToken());//세로

            visited[b+d][a+c]=true;
        }

        //가로(첫번째 행) 초기화
        for(int i=1;i<=m;i++){
            if(visited[0][2*i-1]) break;
            dp[0][i]=1;
        }

        //세로(첫번째 열) 초기화
        for(int i=1;i<=n;i++){
            if(visited[2*i-1][0]) break;
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!visited[i*2-1][j*2]) dp[i][j]+=dp[i-1][j];//세로로 들어오는 공사도로가 없으면 +
                if(!visited[i*2][j*2-1]) dp[i][j]+=dp[i][j-1];//가로로 들어오는 공사도로가 없으면 +
            }
        }

        System.out.println(dp[n][m]);
    }
}

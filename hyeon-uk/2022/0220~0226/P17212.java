import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P17212 {
    public static int dp[]=new int[100001];
    public static int money[]=new int[]{1,2,5,7};
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        Arrays.fill(dp,10000000);
        dp[0]=0;
        for(int i=0;i<4;i++){
            int now=money[i];
            for(int j=now;j<=n;j++){
                dp[j]=Math.min(dp[j],1+dp[j-now]);
            }
        }
        System.out.println(dp[n]);
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ11568 {
    static int[] dp;
    static int n;
    static int[] arr;
    static int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dp = new int[n+1];
        arr = new int[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        int idx=0;
        result = 1;
        while (st.hasMoreTokens()){
            arr[++idx] = Integer.parseInt(st.nextToken());
        }

        dp[1] = 1;
        for (int i=2; i<=n; i++){
            dp[i] = 1;
            for (int j=i; j>=0; j--){
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            result = Math.max(result, dp[i]);
        }
        System.out.println(result);
    }
}

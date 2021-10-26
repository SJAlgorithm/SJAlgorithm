import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[] v;
    static int[] dp;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        v=new int[n];
        dp=new int[n];

        for(int i=0;i<n;i++){
            v[i]=sc.nextInt();
        }
        sc.close();

        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0]=0;

        for(int i=0;i<n;i++){
            if(dp[i]==Integer.MAX_VALUE) continue;
            int canGo=v[i]+i;
            for(int j=i+1;j<=canGo&&j<n;j++){
                dp[j]=Math.min(dp[j],dp[i]+1);
            }
        }
        System.out.println(dp[n-1]==Integer.MAX_VALUE?-1:dp[n-1]);
    }
}

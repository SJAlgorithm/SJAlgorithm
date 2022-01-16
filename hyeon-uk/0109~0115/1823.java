import java.util.Scanner;


public class Main {

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int dp[][];
        int arr[];
        int n;
        n=sc.nextInt();
        dp=new int[n+1][n+1];
        arr=new int[n+1];
        for(int i=1;i<=n;i++) arr[i]=sc.nextInt();

        for(int i=1;i<=n;i++){
            dp[i][i]=arr[i]*n;

            for(int j=i-1;j>0;j--){
                dp[j][i]=Math.max(dp[j+1][i]+arr[j]*(n-i+j),dp[j][i-1]+arr[i]*(n-i+j));
            }
        }

        System.out.println(dp[1][n]);

        sc.close();
    }
}

import java.util.Scanner;

public class P20162 {
    public static int[] dp;
    public static int[] food;
    public static int n;
    public static int ret=0;


    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        n=sc.nextInt();
        food=new int[n+1];
        dp=new int[n+1];

        for(int i=1;i<=n;i++){
            food[i]=sc.nextInt();
        }
        for(int i=1;i<=n;i++){
            dp[i]=food[i];
            for(int j=0;j<i;j++){
                if(food[i]>food[j]){
                    dp[i]=Math.max(dp[i],dp[j]+food[i]);
                }
            }
            ret=Math.max(ret,dp[i]);
        }
        System.out.println(ret);
    }
}

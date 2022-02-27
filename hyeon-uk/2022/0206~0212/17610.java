import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P17610 {
    public static int[] numbers;
    public static boolean[] dp;
    public static int sum=0;
    public static int k;
    public static void dfs(int index,int left,int right){
        if(right-left>=0&&right-left<=sum){
            dp[right-left]=true;
        }
        if(index==k) return;

        dfs(index+1,left+numbers[index],right);
        dfs(index+1,left,right+numbers[index]);
        dfs(index+1,left,right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        k=Integer.parseInt(st.nextToken());
        numbers=new int[k];
        String str=br.readLine();
        st=new StringTokenizer(str," ");
        for(int i=0;i<k;i++){
            numbers[i]=Integer.parseInt(st.nextToken());
            sum+=numbers[i];
        }
        dp=new boolean[sum+1];
        
        dfs(0,0,0);
        int ret=0;
        for(boolean can:dp){
            if(!can)ret++;
        }
        System.out.println(ret);
    }
}

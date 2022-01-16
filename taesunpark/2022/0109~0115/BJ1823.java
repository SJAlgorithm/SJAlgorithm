import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class BJ1823{

    public static int[] plant = new int[2001];
    public static int[][] dp = new int[2001][2001];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int num = Integer.parseInt(br.readLine());

        for(int i=1; i<= num; i++){
            plant[i] = Integer.parseInt(br.readLine());
        }

        bw.write(String.valueOf(play(1, num, 1)));
        bw.flush();
        bw.close();
        br.close();
    }

    public static int play(int s, int e, int n){
        if(s > e)
            return 0;
        if(dp[s][e] != 0)
            return dp[s][e];
        int first = play(s+1, e, n) + n * plant[s];
        int last = play(s, e-1, n) + n * plant[e];

        dp[s][e] = Math.max(first, last);

        return dp[s][e];
    }

}

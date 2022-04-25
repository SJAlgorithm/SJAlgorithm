import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BJ1719 {

    public static int n,m;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] list = new int[n+1][n+1];
        int[][] path = new int[n+1][n+1];

        for(int i=0;i<n+1; i++){
            Arrays.fill(list[i], 10001);
            list[i][i] = 0;
        }

        for(int i=0; i<m; i++){
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            int home = Integer.parseInt(st1.nextToken());
            int target = Integer.parseInt(st1.nextToken());
            int weight = Integer.parseInt(st1.nextToken());
            list[home][target] = weight;
            list[target][home] = weight;

            path[home][target]= home;
            path[target][home] = target;
        }

        for(int k=1; k<n+1; k++){
            for(int i=1; i<n+1; i++){
                for(int j=1; j<n+1; j++){
                    if(list[i][j] > list[i][k] + list[k][j]){
                        list[i][j] = list[i][k] + list[k][j];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(i==j) sb.append("- ");
                else sb.append(path[j][i]+" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);

    }
}

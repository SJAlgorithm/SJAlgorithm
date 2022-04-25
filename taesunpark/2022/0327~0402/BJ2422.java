import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2422 {
    static int n;
    static int m;
    static int[][] map;
    static boolean[] check;
    static int result;
    static int[] data = new int[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        map = new int[n+1][n+1];
        check = new boolean[n+1];

        for (int i=0; i<m; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()){
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                map[a][b] = 1;
                map[b][a] = 1;
            }
        }

        dfs(0,0);
        System.out.print(result);
    }
    static void dfs(int depth, int index){
        if (depth == 3){
            if (validate()){
                result++;
            }
            return;
        }

        for (int i = index+1; i<=n; i++){
            if (check[i] == true) continue;
            check[i] = true;
            data[depth] = i;
            dfs(depth+1, i);
            check[i] = false;
        }
    }
    static boolean validate(){
        for (int i=0; i<2; i++){
            for (int j=i+1; j<3; j++){
                if (map[data[i]][data[j]] == 1) return false;
            }
        }
        return true;
    }

}

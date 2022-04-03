import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ3980 {
    static int n;
    static int[][] map;
    static boolean[] check;
    static int[] data;
    static int max;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        while (n > 0) {
            max = 0;
            map = new int[11][11];
            data = new int[11];
            check = new boolean[11];

            for (int i = 0; i < 11; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int idx = 0;

                while (st.hasMoreTokens()) {
                    map[i][idx++] = Integer.parseInt(st.nextToken());
                }
            }
            dfs(0);
            sb.append(max + "\n");
            n--;
        }
        System.out.print(sb);
    }

    public static void dfs(int depth){

        if (depth == 11){
            int tmp_max = 0;
            for (int i=0; i<11; i++){
                tmp_max += data[i];
            }
            if (tmp_max >= max){
                max = tmp_max;
            }
            return;
        }

        for (int i=0; i<11; i++){
            if (check[i] == true || map[depth][i] == 0) continue;
            check[i] = true;
            data[i] = map[depth][i];
            dfs(depth+1);
            check[i] = false;
        }

    }
}

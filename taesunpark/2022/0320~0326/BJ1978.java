import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ1978 {
    static int n;
    static int[] list;
    static int cnt=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        list = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int index = 0;
        while (st.hasMoreTokens()){
            list[index++] = Integer.parseInt(st.nextToken());
        }

        for (int i=0; i<list.length; i++){
            cnt += sosu(list[i]);
        }
        System.out.print(cnt);
    }
    public static int sosu(int num){
        if (num == 1) return 0;
        if (num == 2) return 1;
        for (int i = 2; i<num; i++){
            if (num % i == 0) return 0;
        }
        return 1;
    }
}

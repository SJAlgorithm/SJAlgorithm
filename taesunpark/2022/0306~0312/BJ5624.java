import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ5624 {
    public static void main(String[] args) throws IOException {
        int n;
        int[] array;
        boolean[] isCheckdList = new boolean[400002];
        int cnt = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        array = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i =0; i<n; ++i){
            array[i] = Integer.parseInt(st.nextToken());
            for (int j=0; j<i; ++j){
                int number = array[i] - array[j];
                if (isCheckdList[number+200000]){
                    cnt++;
                    break;
                }
            }
            for (int j=0; j<=i; ++j){
                isCheckdList[array[i]+array[j]+200000] = true;
            }
        }
        System.out.print(cnt);
    }
}

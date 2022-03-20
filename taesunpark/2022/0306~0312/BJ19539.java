import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ19539 {
    public static void main(String[] args) throws IOException {
        int n;
        int arr[];
        int index=0;
        int sum = 0;
        int cnt = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        while (st.hasMoreTokens()){
            arr[index] = Integer.parseInt(st.nextToken());
            sum += arr[index];
            cnt = arr[index++] / 2;
        }
        if (sum % 3 == 0 && cnt >= sum/3){
            System.out.printf("YES");
        } else{
            System.out.printf("NO");
        }

    }
}

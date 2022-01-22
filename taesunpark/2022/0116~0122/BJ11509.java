import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class BJ11509 {

    public static void main(String[] args) throws IOException {

        int count = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] list = new int[n];

        StringTokenizer sn = new StringTokenizer(br.readLine());

        for(int i=0; i<n;i++){
            list[i] = Integer.parseInt(sn.nextToken());
        }

        for(int i=0; i<n; i++){
            if(list[i] == 0) continue;
            count++;
            for(int j = i+1; j<n; j++){
                if(list[i] - list[j] == 1){
                    list[j] = 0;
                    list[i]--;
                }
            }
        }
        System.out.println(count);



    }
}

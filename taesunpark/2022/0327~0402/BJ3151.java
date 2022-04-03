import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BJ3151 {
    static int n;
    static int[] list;
    static ArrayList<Integer> sumList;
    static long result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        sumList = new ArrayList<>();
        list = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        int idx = 0;
        while (st.hasMoreTokens()) {
            list[idx++] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(list);

        for (int i=0; i<n; i++){
            int start=i+1;
            int end = n-1;

            if (list[i] > 0){
                break;
            }

            while (start<end){
                int currentValue = list[start] + list[end] + list[i];
                int st1=1;
                int en=1;
                if (currentValue == 0){
                    if (list[start] == list[end]){
                        result += combination(end - start +1);
                        break;
                    }
                    while (start+1 < end && list[start] == list[start+1]){
                        start++;
                        st1++;
                    }

                    while (end-1 > start && list[end] == list[end-1]){
                        end--;
                        en++;
                    }

                    result += en*st1;
                }

                if(currentValue > 0){
                    end--;
                } else{
                    start++;
                }
            }
        }
        System.out.print(result);
    }
    public static int combination(int num){
        return num * (num -1) / 2;
    }

}

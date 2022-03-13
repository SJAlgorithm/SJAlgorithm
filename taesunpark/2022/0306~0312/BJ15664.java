import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class BJ15664 {

    static int n,m;
    static boolean[] isUsed;
    static int[] array;
    static int[] result;
    static Set set = new HashSet<String>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] a = br.readLine().split(" ");
        n = Integer.parseInt(a[0]);
        m = Integer.parseInt(a[1]);
        isUsed = new boolean[10];
        array = new int[n];
        result = new int[10];
        String[] b = br.readLine().split(" ");

        for (int i=0; i<b.length; i++){
            array[i] = Integer.parseInt(b[i]);
        }

        Arrays.sort(array);

        bfs(0);
    }
    public static void bfs(int k){
        if (k == m){
            if (!set.contains(Arrays.toString(result))){
                set.add(Arrays.toString(result));
                for (int i=0; i<m; i++){
                    System.out.print(result[i]+" ");
                }
                System.out.print("\n");
                return;
            }
            return;
        }

        int prev = -1;
        if (k-1 >= 0){
            prev = result[k-1];
        }

        for (int i=0; i<n; i++){
            if (!isUsed[i] && prev <= array[i]){
                prev = array[i];
                isUsed[i] = true;
                result[k] = prev;
                bfs(k+1);
                isUsed[i] = false;
            }
        }
    }
}

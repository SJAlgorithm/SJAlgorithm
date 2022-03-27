import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ5052 {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        while (n-- > 0){
            int m = Integer.parseInt(br.readLine());
            String[] str = new String[m];
            for (int i=0; i<m; i++){
                str[i] = br.readLine();
            }
            Arrays.sort(str);

            if (isCheck(str)){
                sb.append("YES" + "\n");
            } else{
                sb.append("NO" + "\n");
            }

        }
        System.out.print(sb);
    }

    static boolean isCheck(String[] str){
        for (int i=1; i<str.length;i++){
            if (str[i].startsWith(str[i-1])) return false;
        }
        return true;
    }
}

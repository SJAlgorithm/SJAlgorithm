import java.util.Arrays;
import java.util.Scanner;

public class BJ2204 {
    public static void main(String[] args){
        String[] str2 = new String[1001];
        Scanner sc = new Scanner(System.in);

        int n;
        n = sc.nextInt();

        int count = 0;

        while(true) {

            if(n == 0){
                for(int i=0;i<count;i++){
                    System.out.println(str2[i]);
                }
                break;
            }

            String[] str = new String[n];

            for (int i = 0; i < n; i++) {
                String a = sc.next();
                str[i] = a;
            }

            Arrays.sort(str, String.CASE_INSENSITIVE_ORDER);

            str2[count++] = str[0];
            n = sc.nextInt();
        }
    }
}

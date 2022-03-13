import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ1864 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true){
            String str = br.readLine();
            if (str.equals("#")) break;
            int[] str2 = new int[str.length()];

            for (int i=0; i<str.length(); i++){
                switch (str.charAt(i)){
                    case '-':
                        str2[i] = 0;
                        break;
                    case '\\':
                        str2[i] = 1;
                        break;
                    case '(':
                        str2[i] = 2;
                        break;
                    case '@':
                        str2[i] = 3;
                        break;
                    case '?':
                        str2[i] = 4;
                        break;
                    case '>':
                        str2[i] = 5;
                        break;
                    case '&':
                        str2[i] = 6;
                        break;
                    case '%':
                        str2[i] = 7;
                        break;
                    case '/':
                        str2[i] = -1;
                        break;
                }
            }

            int result = 0;
            for (int i=str2.length-1, index=0; i>=0; i--, index++){
                result += Math.pow(8,i) * str2[index];
            }
            System.out.println(result);
        }

    }
}

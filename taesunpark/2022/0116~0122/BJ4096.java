import java.util.Scanner;

public class BJ4096 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[] list = new char[11];
        StringBuffer sb = new StringBuffer();

        while(true){
            String str = sc.next();
            int len = str.length();
            int num = Integer.parseInt(str);
            int count = 0;
            boolean check = false;

            if(num == 0 && len == 1){
                break;
            }



            while(true) {
                str = Integer.toString(num);
                for(int i=str.length();i<len; i++){
                    str = "0"+str;
                }

                for(int i=0; i<str.length();i++){
                    list[i] = str.charAt(i);
                }

                for (int i = 0, j = str.length() - 1; i < str.length() / 2; i++, j--) {
                    if (list[i] == list[j]) {
                        check = true;
                    } else {
                        check = false;
                        break;
                    }
                }
                if (check == true) {
                    sb.append(count+"\n");
                    break;
                } else {
                    num++;
                    count++;
                }
            }
        }
        System.out.print(sb.toString());
    }
}

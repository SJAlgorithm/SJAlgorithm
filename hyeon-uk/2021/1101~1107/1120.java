import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        String a,b;
        int ret=51,gap;
        Scanner scanner = new Scanner(System.in);
        a=scanner.next();
        b=scanner.next();
        for(int i=0;i<=b.length()-a.length();i++){
            gap=0;
            for(int j=0;j<a.length();j++){
                if(a.charAt(j)!=b.charAt(i+j)){
                   gap++;
                }
            }
            ret=Math.min(ret,gap);
        }
        System.out.println(ret);
    }
}

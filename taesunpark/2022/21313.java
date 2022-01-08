package 바킹독.연습문제0x05;
import java.util.Scanner;

public class BJ21313 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=0; i<n; i++){
            if(i % 2 == 0){
                if(i == 0){
                    System.out.print("1");
                } else if(i == n-1){
                    System.out.print(" 3");
                } else{
                    System.out.print(" 1");
                }

            } else{
                System.out.print(" 2");
            }
        }

    }
}

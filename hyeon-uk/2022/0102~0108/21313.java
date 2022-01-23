import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();

        for(int i=0;i<n;i++){
            if(i==n-1){
                if(n%2==0) System.out.print(2);
                else System.out.print(3);
            }
            else if(i%2==0)  {
                System.out.print(1);
            }
            else{
                System.out.print(2);
            }
            System.out.print(" ");
        }
    }
}

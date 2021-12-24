import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();

        while((t--)>0){
            int even=0;
            int odd=0;
            int n=sc.nextInt();
            for(int i=0;i<n;i++){
                int temp=sc.nextInt();
                if(i%2==0&&temp==1){
                    even++;
                }
                else if(i%2==1&&temp==1){
                    odd++;
                }
            }
            if(n%2==1 || (n%2==0 && Math.abs(even-odd)<=1)){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}

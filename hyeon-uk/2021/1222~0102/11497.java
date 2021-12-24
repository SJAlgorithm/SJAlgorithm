import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();

        while((t--)>0){
            int n=sc.nextInt();
            int[] array=new int[n];
            int[] array2=new int[n];
            int result=0;
            for(int i=0;i<n;i++){
                array[i]=sc.nextInt();
            }
            Arrays.sort(array);
            for(int i=0;i<n;i++){
                if(i%2==0){
                    array2[i/2]=array[i];
                }
                else{
                    array2[n-1-(i/2)]=array[i];
                }
            }
            for(int i=0;i<n;i++){
                int gap=Math.abs(array2[i]-array2[(i+1)%n]);
                result=Math.max(gap,result);
            }
            System.out.println(result);
        }
        sc.close();
    }
}

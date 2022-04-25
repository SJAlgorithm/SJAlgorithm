import java.awt.*;
import java.util.*;

public class P11509 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();
        int[] h=new int[1000001];
        int cnt=0;
        for(int i=0;i<n;i++){
            int data=sc.nextInt();
            if(h[data]==0){
                cnt++;
            }
            else{
                h[data]--;
            }
            if(data-1>0) h[data-1]++;
        }
        System.out.println(cnt);
    }
}
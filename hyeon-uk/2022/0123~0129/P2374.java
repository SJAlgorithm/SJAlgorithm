import java.util.Scanner;

public class P2374{
    public static long[] arr;
    public static int n;
    public static long ret=0l;

    public static void func(int left,int right, Long lastMax){
        if(left>right){
            return;
        }

        long max=0l;
        for(int i=left;i<=right;i++) {
            max=Math.max(arr[i],max);
        }

        int ind=-1;
        for(int i=left;i<=right;i++){
            if(arr[i]==max){
                ind=i;
                break;
            }
        }

        func(left,ind-1,max);
        func(ind+1,right,max);
        ret+=(lastMax-max);
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();

        arr=new long[n+1];

        long max=0l;
        for(int i=0;i<n;i++) {
            arr[i]=sc.nextLong();
            max=Math.max(arr[i],max);
        }

        int ind=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==max){
                ind=i;
                break;
            }
        }

        func(0,ind-1,max);
        func(ind+1,n-1,max);


        System.out.println(ret);
    }
}

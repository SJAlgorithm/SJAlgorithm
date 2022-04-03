import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static boolean check[][];
    public static int n,m;
    public static long ret=0;
    public static int arr[];

    public static int upper_bound(int left,int right,int target){
        while(left<right){
            int middle=(left+right)>>1;
            if(arr[middle]<=target){
                left=middle+1;
            }
            else{
                right=middle;
            }
        }
        return right;
    }

    public static int lower_bound(int left,int right,int target){
        while(left<right){
            int middle=(left+right)>>1;

            if(arr[middle]>=target){
                right=middle;
            }
            else{
                left=middle+1;
            }
        }
        return right;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        arr=new int[n];
        check=new boolean[n][n];
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int target=(arr[i]+arr[j])*-1;
                int ind1=lower_bound(j+1,n,target);
                if(ind1<n&&arr[ind1]==target){
                    int ind2=upper_bound(j+1,n,target);
                    ret+=(ind2-ind1);
                }
            }
        }
        System.out.println(ret);
    }
}

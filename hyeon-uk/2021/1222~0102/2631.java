import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static int lower_bound(Vector<Integer> arr,int number){
        int i,middle,left,right;
        left=0;
        right=arr.size()-1;
        while(left<=right){
            middle=(left+right)>>1;
            if(arr.get(middle)>number){
                right=middle-1;
            }
            else if(arr.get(middle)<number){
                left=middle+1;
            }
        }

        return left;
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Vector<Integer> line = new Vector<>();

        for(int i=0;i<n;i++){
            int num=sc.nextInt();

            if(line.isEmpty()){
                line.add(num);
            }
            else{
                int index=lower_bound(line,num);
                if(line.size()<=index) line.add(num);
                else line.set(index,num);
            }
        }
        System.out.println(n-line.size());
    }
}

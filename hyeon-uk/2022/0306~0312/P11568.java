import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P11568 {
    public static int n;
    public static Vector<Integer> list=new Vector<>();
    public static int lower_bound(Vector<Integer> list,int start,int end,int target){
        while(start<=end){
            int middle=(start+end)/2;

            if(list.get(middle)>=target){
                end=middle-1;
            }
            else{
                start=middle+1;
            }
        }
        return start;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<n;i++){
            int now=Integer.parseInt(st.nextToken());
            if(list.isEmpty()){
                list.add(now);
            }
            else{
                int index=lower_bound(list,0,list.size()-1,now);
                if(list.size()<=index){
                    list.add(now);
                }
                else {
                    list.set(index, now);
                }
            }
        }
        System.out.println(list.size());
    }
}

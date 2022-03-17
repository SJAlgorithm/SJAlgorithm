import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P11722 {
    public static int lower_bound(Vector<Integer> list,int start,int end,int target){
        while(start<=end){
            int middle=(start+end)>>1;

            if(list.get(middle)<=target){
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
        int n=Integer.parseInt(br.readLine());
        Vector<Integer> list=new Vector<>();
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<n;i++){
            int now=Integer.parseInt(st.nextToken());
            if(list.isEmpty()){
                list.add(now);
            }else{
                int ind=lower_bound(list,0,list.size()-1,now);
                if(list.size()<=ind){
                    list.add(now);
                }
                else{
                    list.setElementAt(now,ind);
                }
            }
        }

        System.out.println(list.size());
    }
}

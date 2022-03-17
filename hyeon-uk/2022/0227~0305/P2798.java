import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P2798 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        List<Integer> list=new ArrayList<>();
        st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<n;i++){
            list.add(Integer.parseInt(st.nextToken()));
        }
        int ret=0;
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                for(int k=0;k<list.size();k++){
                    if(i!=j&&j!=k&&k!=i){
                        int sum=list.get(i)+list.get(j)+list.get(k);
                        if(sum<=m){
                            ret=Math.max(ret,sum);
                        }
                    }
                }
            }
        }
        System.out.println(ret);
    }
}

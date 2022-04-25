import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P9375 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t-->0){
            int n=Integer.parseInt(br.readLine());
            Map<String,Integer> count=new HashMap<>();
            int kindCnt=0;
            for(int i=0;i<n;i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                String clothes = st.nextToken();
                String kind = st.nextToken();
                if(count.get(kind)==null){
                    count.put(kind,0);
                }
                count.put(kind, count.get(kind) + 1);
            }
            int ret = 1;
            for (int value : count.values()) {
                ret *= (value+1);
            }
            System.out.println(ret-1);
        }
    }
}

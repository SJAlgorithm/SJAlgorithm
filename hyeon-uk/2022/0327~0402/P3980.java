import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static boolean check[]=new boolean[11];
    public static int ret=0;
    public static void dfs(List<List<Integer>> arr,int score,int cnt){
        if(cnt==11){
            ret=Math.max(ret,score);
            return;
        }
        for(int i=0;i<11;i++){
            if(!check[i] && arr.get(i).get(cnt)!=0){
                check[i]=true;
                dfs(arr,score+arr.get(i).get(cnt),cnt+1);
                check[i]=false;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t-- > 0 ) {
            List<List<Integer>> arr=new LinkedList<>();
            for(int i=0;i<11;i++){
                arr.add(new LinkedList<>());
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                for(int j=0;j<11;j++){
                    arr.get(i).add(Integer.parseInt(st.nextToken()));
                }
            }
            ret=0;
            Arrays.fill(check,false);
            dfs(arr,0,0);
            System.out.println(ret);
        }
    }
}

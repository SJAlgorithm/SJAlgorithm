import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P15664 {
    public static List<Integer> list=new ArrayList<>();
    public static List<Integer> ret=new ArrayList<>();
    public static Map<String,Boolean> check=new HashMap<>();
    public static int n,m;

    public static void dfs(int index,int cnt){
        if(cnt==m){
            String tempCheck="";
            for(int i=0;i<m;i++){
                tempCheck+= ret.get(i).toString();
            }
            if(check.get(tempCheck)==null){
                check.put(tempCheck,true);
                for(int i=0;i<m;i++){
                    System.out.print(ret.get(i)+" ");
                }
                System.out.println();
            }
            return;
        }
        for(int i=index+1;i<n;i++){
            ret.add(list.get(i));
            dfs(i,cnt+1);
            ret.remove(cnt);
            dfs(i,cnt);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        st=new StringTokenizer(br.readLine(), " ");
        for(int i=0;i<n;i++){
            list.add(Integer.parseInt(st.nextToken()));
        }
        list.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1-o2;
            }
        });

        dfs(-1,0);

    }
}

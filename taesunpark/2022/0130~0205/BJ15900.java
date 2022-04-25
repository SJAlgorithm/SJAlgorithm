import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BJ15900 {
    public static ArrayList<ArrayList<Integer>> arrayLists;
    public static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        arrayLists = new ArrayList<>();

        for(int i=0; i<=n;i++){
            arrayLists.add(new ArrayList<>());
        }

        for(int i=0; i<n-1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arrayLists.get(a).add(b);
            arrayLists.get(b).add(a);
        }

        dfs(1, 0, 0);
        if (result % 2 == 1)
            System.out.printf("Yes");
        else
            System.out.printf("No");
    }

    public static void dfs(int cur, int before, int count){
        for(int num : arrayLists.get(cur)){
            if (num != before){
                dfs(num, cur, count+1);
            }
        }
        if(arrayLists.get(cur).size() == 1){
            result += count;
        }
    }

}
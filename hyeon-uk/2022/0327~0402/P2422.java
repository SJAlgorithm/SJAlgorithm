import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static boolean cantMix[][]=new boolean[201][201];

    public static boolean canMix(int i,int j,int k){
        if(cantMix[i][j]|| cantMix[i][k]||cantMix[j][k]) return false;
        else return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine()," ");
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            if(a>b){
                int temp=a;
                a=b;
                b=temp;
            }
            cantMix[a][b]=true;
        }
        int ret=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(canMix(i,j,k)) ret++;
                }
            }
        }
        System.out.println(ret);
    }
}

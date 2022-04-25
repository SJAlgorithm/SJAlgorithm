import java.util.Arrays;
import java.util.Scanner;

public class P1719 {
    public static int[][] weight;
    public static int[][] route;

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        weight=new int[n+1][n+1];
        route=new int[n+1][n+1];

        for(int i=1;i<=n;i++){
            Arrays.fill(weight[i],987654321);
            weight[i][i]=0;
        }

        for(int i=0;i<m;i++){
            int u=sc.nextInt();
            int v=sc.nextInt();
            int w=sc.nextInt();

            weight[u][v]=w;
            weight[v][u]=w;

            route[u][v]=v;
            route[v][u]=u;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(weight[i][j] > weight[i][k]+weight[k][j]){
                        weight[i][j]=weight[i][k]+weight[k][j];
                        route[i][j]=route[i][k];
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    System.out.print("- ");
                }
                else {
                    System.out.print(route[i][j]+ " ");
                }
            }
            System.out.println();
        }


    }
}

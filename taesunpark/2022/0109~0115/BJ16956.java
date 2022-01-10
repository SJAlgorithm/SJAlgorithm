import java.util.Scanner;

public class BJ16956 {

    static int n;
    static int m;
    static char[][] map;
    static String cmd;
    static int[] dX = {1,0,-1,0};
    static int[] dY = {0,1,0,-1};

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        map = new char[n][m];

        for(int i=0;i<n;i++){
            cmd = sc.next();
            for(int j=0; j<m; j++){
                map[i][j] = cmd.charAt(j);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 'W'){
                    for(int dir=0; dir<4; dir++){
                        int nx = i+dX[dir];
                        int ny = j+dY[dir];
                        if(nx<0 || ny <0 || nx>=n || ny>=m) continue;
                        if(map[i+dX[dir]][j+dY[dir]] == '.'){
                            map[i+dX[dir]][j+dY[dir]] = 'D';
                        }
                        if(map[i+dX[dir]][j+dY[dir]] == 'S'){
                            System.out.println("0");
                            return;
                        }
                    }
                }
            }
        }
        System.out.println("1");

        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                System.out.print(map[i][j]);
            }
            System.out.print('\n');
        }
    }
}

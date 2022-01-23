import java.util.Scanner;

public class Main {
    public static int[] dice=new int[6]; //위, 아래, 동,서,남,북
    public static int[] mx=new int[]{0,0,-1,1};
    public static int[] my=new int[]{1,-1,0,0};
    public static int[][] maze;
    public static int n,m,x,y,k;
    public static final int UP=0,DOWN=1,EAST=2,WEST=3,SOUTH=4,NORTH=5;
    public static boolean isIn(int x,int y){
        return x>=0&&x<n&&0<=y&&y<m;
    }
    public static void moveDice(int op){
        int temp;
        if(op==0){//동
            //동->아래
            //아래->서
            //서->위
            //위->동
            temp=dice[EAST];
            dice[EAST]=dice[UP];
            dice[UP]=dice[WEST];
            dice[WEST]=dice[DOWN];
            dice[DOWN]=temp;
        }
        else if(op==1){//서
            //서->아래
            //아래->동
            //동->위
            //위->서
            temp=dice[WEST];
            dice[WEST]=dice[UP];
            dice[UP]=dice[EAST];
            dice[EAST]=dice[DOWN];
            dice[DOWN]=temp;
        }
        else if(op==2){//북
            //북->아래
            //아래->남
            //남->위
            //위->북
            temp=dice[NORTH];
            dice[NORTH]=dice[UP];
            dice[UP]=dice[SOUTH];
            dice[SOUTH]=dice[DOWN];
            dice[DOWN]=temp;
        }
        else{//남
            //남->아래
            //아래->북
            //북->위
            //위->남
            temp=dice[SOUTH];
            dice[SOUTH]=dice[UP];
            dice[UP]=dice[NORTH];
            dice[NORTH]=dice[DOWN];
            dice[DOWN]=temp;
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        n=sc.nextInt();
        m=sc.nextInt();
        x=sc.nextInt();
        y=sc.nextInt();
        k=sc.nextInt();

        maze=new int[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maze[i][j]=sc.nextInt();
            }
        }

        for(int i=0;i<k;i++){
            int op=sc.nextInt();
            op--;
            int nx=x+mx[op];
            int ny=y+my[op];

            if(!isIn(nx,ny)) continue;

            if(op==0){//동
                if(maze[nx][ny]!=0) {
                    dice[EAST]=maze[nx][ny];
                    maze[nx][ny]=0;
                }
                else maze[nx][ny]=dice[EAST];
            }
            else if(op==1){//서
                if(maze[nx][ny]!=0){
                    dice[WEST]=maze[nx][ny];
                    maze[nx][ny]=0;
                }
                else maze[nx][ny]=dice[WEST];
            }
            else if(op==2){//북
                if(maze[nx][ny]!=0) {
                    dice[NORTH]=maze[nx][ny];
                    maze[nx][ny]=0;
                }
                else maze[nx][ny]=dice[NORTH];
            }
            else{//남
                if(maze[nx][ny]!=0){
                    
                    dice[SOUTH]=maze[nx][ny];
                    maze[nx][ny]=0;
                }
                else maze[nx][ny]=dice[SOUTH];
            }
            moveDice(op);
            x=nx;
            y=ny;
            System.out.println(dice[UP]);
        }
    }
}

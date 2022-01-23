import java.util.Scanner;

public class BJ2469 {

    static int n,m;
    static char[] firstArr;
    static char[] lastArr;
    static char[] resultArr;
    static char[][] map;
    static int index;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new char[m][n-1];
        firstArr = new char[n];
        lastArr = new char[n];

        for(int i = 0; i<n;i++){
            firstArr[i] = (char) ('A' + i);
        }

        lastArr = sc.next().toCharArray();


        for(int i=0; i<m;i++){
            map[i] = sc.next().toCharArray();
            if(map[i][0] == '?') index = i;
        }

        for(int i=0;i<index;i++){
            for(int j=0; j<n-1; j++){
                if(map[i][j] == '-'){
                    char temp = firstArr[j];
                    firstArr[j] = firstArr[j+1];
                    firstArr[j+1] = temp;
                }
            }
        }

        for(int i=m-1;i>index; i--){
            for(int j=0;j<n-1;j++){
                if(map[i][j] == '-'){
                    char temp = lastArr[j];
                    lastArr[j] = lastArr[j+1];
                    lastArr[j+1] = temp;
                }
            }
        }
        resultArr = new char[n];

        for(int i=0;i<n-1;i++){
            if(firstArr[i] == lastArr[i]){
                resultArr[i] = '*';
            } else if(firstArr[i] == lastArr[i+1] || firstArr[i+1] == lastArr[i]){
                resultArr[i] = '-';
                // 사다리를 탔으니 스왑
                char tmp = firstArr[i];
                firstArr[i] = firstArr[i+1];
                firstArr[i+1] = tmp;
            } else{
                for(int k=0; k<n-1; k++){
                    System.out.print('x');
                }
                return;
            }
        }

        for(int i=0;i<n-1;i++){
            System.out.print(resultArr[i]);
        }

    }
}

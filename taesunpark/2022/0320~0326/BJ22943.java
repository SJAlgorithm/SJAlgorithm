import java.util.Scanner;

public class BJ22943 {
    static boolean[] isNotSosu = new boolean[100000];
    static boolean[] sosuSum = new boolean[100000];
    static boolean[] sosuMult = new boolean[100000];
    static int K,M;
    static int answer;
    static boolean[] visited = new boolean[10];
    static int[] nums;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        M = sc.nextInt();
        nums = new int[K];
        eratos();
        makeSum();
        makeMult();
        perm(0,0);
        System.out.println(answer);
    }
    public static void eratos(){
        isNotSosu[0] = true;
        isNotSosu[1] = true;

        for (int i=2; i<100000; i++){
            if (isNotSosu[i]) continue;
            else {
                for (int j=i+i; j<100000;j += i){
                    isNotSosu[j] = true;
                }
            }
        }
    }
    public static void makeSum(){
        for (int i=2; i< 100000; i++){
            if (isNotSosu[i]) continue;

            for (int j= i+1; j<100000; j++){
                if (isNotSosu[j]) continue;
                if (i+j >= 100000) continue;
                sosuSum[i+j] = true;
            }
        }
    }

    public static void makeMult(){
        for (int i=2; i<100000;i++){
            if (isNotSosu[i])   continue;

            for (int j=i;j<100000;j++){
                if (isNotSosu[j]) continue;

                long num = (long) i * (long) j;
                if (num >= 100000) continue;

                sosuMult[i*j] = true;
            }
        }
    }

    public static void perm(int cnt, int num){
        if (cnt == K){
            if (sosuSum[num]){
                while (true){
                    if(num%M == 0){
                        num /= M;
                    } else{
                        break;
                    }
                }
                if (sosuMult[num]){
                    answer++;
                }
            }
            return;
        }

        for (int i=0; i<10; i++){
            if (cnt == K-1 && i == 0) continue;

            if (visited[i]) continue;

            visited[i] = true;
            nums[cnt] = i;
            perm(cnt +1, num+i*(int)Math.pow(10, cnt));
            visited[i] = false;
        }

    }
}

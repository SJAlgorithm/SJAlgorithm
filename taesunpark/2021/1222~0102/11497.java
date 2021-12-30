import java.util.*;

class Main{

   public static int[] list;

   public static void main(String[] arg){
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();

       for(int i=0; i<n; i++){
           int m = sc.nextInt();
           list = new int[m];

           for(int j=0; j<m; j++){
               list[j] = sc.nextInt();
           }
            System.out.println(rank(m));

       }
   }

   public static int rank(int m){
       int[] tempList = new int[m];
       // 배열 오름차순 정렬
       Arrays.sort(list);
        // 새로운 배열 첫 원소, 끝 원소가 인접하기 때문에 양 끝에 작은 원소들을 놓는 걸 반복해줬음.
       for(int i=0, j=0; j<m/2;i=i+2, j++){
           tempList[j] = list[i];
           tempList[m-j-1] = list[i+1];
       }

       if (m % 2 == 1){
           tempList[m/2] = list[m-1];
       }

       int max = 0;

       for(int i=0;i<m-1;i++){
           int a = tempList[i] - tempList[i + 1];
           if(max < Math.abs(a)){
               max = Math.abs(a);
           }
       }
       return max;
   }
}






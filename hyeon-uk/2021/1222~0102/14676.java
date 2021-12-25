import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n,m,k;
        n=sc.nextInt();
        m=sc.nextInt();
        k=sc.nextInt();

        //Graph
        ArrayList<ArrayList<Integer>> v=new ArrayList<>();
        for(int i=0;i<=n;i++) v.add(new ArrayList<>());

        //Array
        int[] indeg=new int[n+1];
        int[] build=new int[n+1];

        for(int i=0;i<m;i++){
            int x=sc.nextInt();
            int y=sc.nextInt();
            v.get(x).add(y);
            indeg[y]++;
        }

        Boolean cheat=false;
        for(int i=0;i<k;i++){
            int op=sc.nextInt();
            int bNum=sc.nextInt();

            if(op==1){
                if(indeg[bNum]==0){//이전에 생성되어야 할 건물들이 모두 건설되었을때
                    build[bNum]++;//건물개수 ++
                    if(build[bNum]==1) {//처음 건설하는 건물이면, 다음단계 건물들의 진입차수--
                        for (int j = 0; j < v.get(bNum).size(); j++) {
                            int next = v.get(bNum).get(j);
                            indeg[next]--;
                        }
                    }
                }
                else{//이전에 생성되어야할 건물들이 지어지지않았는데 지으려했으므로 cheat=true
                    cheat=true;
                }
            }
            else{
                if(build[bNum]>0){//생성했던 건물들이 1개이상 있을때
                    build[bNum]--;//건물개수 --
                    if(build[bNum]==0){//만약 해당 건물이 모두 없다면 다음단계 건물들의 진입차수++
                        for(int j=0;j<v.get(bNum).size();j++){
                            int next=v.get(bNum).get(j);
                            indeg[next]++;
                        }
                    }
                }
                else{//생성하지도 않은 건물이 파괴되면 cheat=true
                    cheat=true;
                }
            }
        }
        System.out.println(cheat?"Lier!":"King-God-Emperor");
    }
}

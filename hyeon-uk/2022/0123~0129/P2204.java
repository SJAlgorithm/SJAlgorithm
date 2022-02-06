import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class P2204 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        while(true){
            int n=sc.nextInt();
            if(n==0) break;

            List<String> list=new LinkedList<>();
            for(int i=0;i<n;i++){
                String str=sc.next();
                list.add(str);
            }

            list.sort(new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    o1=o1.toLowerCase();
                    o2=o2.toLowerCase();
                    return o1.compareTo(o2);
                }
            });
            System.out.println(list.get(0));
        }
    }
}
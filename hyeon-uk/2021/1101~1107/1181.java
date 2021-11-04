import java.util.*;

public class Main {
    static Vector<String> v=new Vector<>();
    static Map<String,Boolean> check=new HashMap<>();
    static int n;
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        n=scanner.nextInt();

        for(int i=0;i<n;i++){
            String temp=scanner.next();
            if(check.get(temp)==null){
                check.put(temp,true);
                v.add(temp);
            }
        }
        Collections.sort(v, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length()==o2.length()){
                    return o1.compareTo(o2);
                }
                else{
                    return o1.length()-o2.length();
                }
            }
        });
        for(int i=0;i<v.size();i++){
            String str=v.get(i);
            System.out.println(str);
        }
    }
}

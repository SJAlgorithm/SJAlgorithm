import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class P1864 {
    public static Map<Character,Integer> map;

    public static void setting(){
        map=new HashMap<>();
        map.put('-',0);
        map.put('\\',1);
        map.put('(',2);
        map.put('@',3);
        map.put('?',4);
        map.put('>',5);
        map.put('&',6);
        map.put('%',7);
        map.put('/',-1);
    }
    public static int calc(String str){
        int num=1;
        int ret=0;
        for(int i=str.length()-1;i>=0;i--){
            char c=str.charAt(i);
            ret=ret+(map.get(c)*num);
            num*=8;
        }
        return ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        setting();
        while(true){
            String str=br.readLine();
            if(str.equals("#")) break;

            System.out.println(calc(str));
        }
    }
}

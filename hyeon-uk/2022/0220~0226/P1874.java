import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class P1874 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        List<Character> op=new LinkedList<>();
        Stack<Integer> num=new Stack<>();
        int n=Integer.parseInt(br.readLine());
        int data=1;
        for(int i=0;i<n;i++){
            int now=Integer.parseInt(br.readLine());

            if(num.isEmpty()){
                num.push(data++);
                op.add('+');
            }
            if(num.peek()>now){
                System.out.println("NO");
                return;
            }
            while(num.peek()<now){
                num.push(data++);
                op.add('+');
            }
            if(now==num.peek()){
                num.pop();
                op.add('-');
            }
        }

        for (char d : op) {
            System.out.println(d);
        }

    }

}

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static boolean check(String str){
        Queue<Character> q=new LinkedList<>();

        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);

            if(q.isEmpty()||c=='('){
                q.add(c);
            }
            else{
                char p=q.poll();
                if(p==')'){
                    return false;
                }
            }
        }
        if(!q.isEmpty()) return false;
        else return true;
    }
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        String str;
        int n=scanner.nextInt();
        for(int i=0;i<n;i++){
            str=scanner.next();
            if(check(str)){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}

import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static boolean check(String str){
        Stack<Character> q=new Stack<>();

        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);

            if(q.isEmpty()||c=='('){
                q.push(c);
            }
            else{
                char p=q.pop();
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

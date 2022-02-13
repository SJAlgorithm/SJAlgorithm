import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class P2504 {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();

        Stack<Character> st=new Stack<>();
        int ret=0;
        int temp=1;
        boolean flag=true;

        for(int i=0;i<str.length();i++){
            char now=str.charAt(i);
            if(now=='('){
                temp*=2;
                st.push(now);
            }
            else if(now=='['){
                temp*=3;
                st.push(now);
            }
            else{
                if(now==')'&&!st.isEmpty()&&st.peek()=='('){
                    if(str.charAt(i-1)=='('){
                        ret+=temp;
                    }
                    st.pop();
                    temp/=2;
                }
                else if(now==']'&&!st.isEmpty()&&st.peek()=='['){
                    if(str.charAt(i-1)=='['){
                        ret+=temp;
                    }
                    st.pop();
                    temp/=3;
                }
                else{
                    flag=false;
                    break;
                }
            }
        }
        if(!st.isEmpty() || !flag){
            System.out.println(0);
        }
        else{
            System.out.println(ret);
        }
    }
}

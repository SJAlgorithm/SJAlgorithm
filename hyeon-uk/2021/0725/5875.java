import java.util.Scanner;
import java.util.Stack;


public class baekjoon {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        int len=str.length();
        int total=0;
        int left_cnt=0;
        int right_cnt=0;
        int[] left= new int[len];
        int[] right=new int[len];

        Stack<Integer> left_st=new Stack<>();
        Stack<Integer> right_st=new Stack<>();

        for(int i=0;i<len;i++){
            char now=str.charAt(i);
            if(now=='('){
                left_st.push(i);
                left_cnt++;
                total++;
            }
            else{
                right_cnt++;
                total--;
                if(!left_st.isEmpty()){
                    left_st.pop();
                }
                else{
                    //짝이 안맞는 닫는 괄호 저장
                    right_st.push(i);
                }
            }
            //누적합 저장
            left[i]=left_cnt;
            right[i]=right_cnt;
        }

        int result;
        //여는 괄호가 더 많을때
        if(total>0){
            result=left[len-1]-left[left_st.pop()]+1;
        }
        //여는괄호와 닫는괄호가 같을떄는 올바른 경우이므로, 건들 ㄴㄴ
        else if(total==0){
            result=0;
        }
        //닫는 괄호가 더 많을때
        else{
            while(right_st.size()!=1) right_st.pop();
            result=right[right_st.pop()];
        }
        System.out.println(result);
    }
}

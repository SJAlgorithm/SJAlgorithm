import java.util.Scanner;

public class P4096{
    public static boolean isPal(String str){
        int len=str.length();
        for(int i=0;i<str.length()/2;i++){
            if(str.charAt(i)!=str.charAt(len-1-i)) return false;
        }
        return true;
    }

    public static String intToString(int num,int len){
        String str=Integer.toString(num);
        while(str.length()<len) str="0"+str;
        return str;
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        while(true){
            String str=sc.next();
            if(str.equals("0")) break;
            int len=str.length();
            int cnt=0;
            while(!isPal(str)){
                cnt++;
                int next=(Integer.parseInt(str)+1);
                str=intToString(next,len);
            }
            System.out.println(cnt);
        }
    }
}
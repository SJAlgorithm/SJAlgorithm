import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class P14391 {
    public static int maze[]=new int[16];
    public static boolean row[]=new boolean[16];
    public static int n,m;
    public static long ret=0l;

    public static void calc(){
        long total=0l;
        long temp=0l;
        //가로로 묶인것들의 합
        for(int i=0;i<n;i++){
            temp=0;
            for(int j=0;j<m;j++){
                int ind=i*m+j;
                if(row[ind]){
                    temp=temp*10+maze[ind];
                }
                else{
                    total+=temp;
                    temp=0;
                }
            }
            if(temp!=0) {
                total += temp;//짬처리
                temp=0;
            }
        }
        //세로로 묶인것들의 합
        for(int j=0;j<m;j++){
            temp=0;
            for(int i=0;i<n;i++){
                int ind=i*m+j;
                if(!row[ind]){
                    temp=temp*10+maze[ind];
                }
                else{
                    total+=temp;
                    temp=0;
                }
            }
            if(temp!=0){
                total+=temp;
                temp=0;
            }
        }
        ret=Math.max(ret,total);
    }

    public static void func(int index){
        if(index==n*m){
            calc();
            return;
        }

        //해당칸을 세로로했을때
        func(index+1);

        //해당칸을 가로로했을때
        row[index]=true;
        func(index+1);
        row[index]=false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        for(int i=0;i<n;i++){
            String line=br.readLine();
            for(int j=0;j<m;j++){
                maze[i*m+j]=(int)(line.charAt(j)-'0');
            }
        }
        func(0);
        System.out.println(ret);
    }
}

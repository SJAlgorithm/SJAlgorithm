import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.regex.Pattern;

public class P7682 {
    public static String check(String str){
        char maze[][]=new char[3][3];
        int xCount=0;
        int oCount=0;
        for(int i=0;i<9;i++){
            maze[i/3][i%3]=str.charAt(i);
            if(str.charAt(i)=='X') xCount++;
            if(str.charAt(i)=='O') oCount++;
        }

        boolean xWin=false;
        boolean oWin=false;

        //가로 세로로 누가 이겼는지 확인
        for(int i=0;i<3;i++){
            if(maze[i][0]==maze[i][1]&&maze[i][1]==maze[i][2]){
                if(maze[i][0]=='X') xWin=true;
                if(maze[i][0]=='O') oWin=true;
            }
            if(maze[0][i]==maze[1][i]&&maze[1][i]==maze[2][i]){
                if(maze[0][i]=='X') xWin=true;
                if(maze[0][i]=='O') oWin=true;
            }
        }

        //대각선도 확인
        if(maze[0][0]==maze[1][1]&&maze[1][1]==maze[2][2] || maze[0][2]==maze[1][1]&&maze[1][1]==maze[2][0]){
            if(maze[1][1]=='X') xWin=true;
            if(maze[1][1]=='O') oWin=true;
        }

        if(xWin&&!oWin&&xCount-oCount==1) return "valid";
        else if(!xWin&&oWin&&xCount==oCount) return "valid";
        else if(!xWin&&!oWin&&xCount==5&&oCount==4) return "valid";
        else return "invalid";
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String str=br.readLine();
            if(str.equals("end")) break;

            System.out.println(check(str));
        }
    }
}

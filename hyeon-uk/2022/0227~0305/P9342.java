import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.regex.Pattern;

public class P9342 {
    public static String check(String st){
        String pattern="^[A-F]?A+F+C+[A-F]?$";
        boolean regex= Pattern.matches(pattern,st);
        return !regex ? "Good" : "Infected!";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t-->0){
            String st=br.readLine();
            System.out.println(check(st));
        }
    }
}

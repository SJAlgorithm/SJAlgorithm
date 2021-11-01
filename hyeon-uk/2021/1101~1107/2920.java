import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        char[] melody=new char[]{'c','d','e','f','g','a','b','C'};
        String asc="cdefgabC";
        String des="Cbagfedc";
        String ret="";
        Scanner scanner=new Scanner(System.in);
        for(int i=0;i<8;i++){
            int n=scanner.nextInt();
            ret+=melody[n-1];
        }
        if(ret.equals(asc)){
            System.out.println("ascending");
        }
        else if(ret.equals(des)){
            System.out.println("descending");
        }
        else{
            System.out.println("mixed");
        }

    }
}

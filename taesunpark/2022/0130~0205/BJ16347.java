import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BJ16347 {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static ArrayList<Integer>[] nodes;
    private static int[] score;
    private static char[] animal;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        nodes = new ArrayList[n+1];
        animal = new char[n+1];
        score = new int[n+1];

        for (int i=0; i<n+1;i++){
            nodes[i] = new ArrayList<Integer>();
        }
        for(int Index=2; Index< n+1; Index++){
            st = new StringTokenizer(br.readLine());
            char NodeAnimal = st.nextToken().charAt(0);
            int amount = Integer.parseInt(st.nextToken());
            int nextNode = Integer.parseInt(st.nextToken());

            animal[Index] = NodeAnimal;
            score[Index] = amount;
            nodes[nextNode].add(Index);
        }
        System.out.println(order(1));
    }
    private static long order(int node){
        long sum = 0;
        for(int next:nodes[node]){
            sum += order(next);
        }
        if(animal[node] == 'S'){
            return sum+score[node];
        } else{
            return (sum - score[node] >= 0) ? sum - score[node] : 0;
        }
    }
}

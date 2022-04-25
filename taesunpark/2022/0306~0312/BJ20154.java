import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class BJ20154 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        Deque<Integer> deque = new ArrayDeque();

        int[] array = {3, 2, 1,	2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};

        for (int i=0 ; i<str.length(); i++){
            deque.add(array[str.charAt(i)- 'A']);
        }
        int a,b;
        int size = deque.size();
        while (true){
            if (size == 1)
                break;

            for (int i=0; i<size; i += 2){
                if (i == size-1){
                    deque.addLast(deque.pollFirst());
                    break;
                }
                a = deque.pollFirst();
                b = deque.pollFirst();
                deque.addLast((a+b) % 10);
            }
            size = deque.size();
        }
        int result = deque.poll();

        if(result % 2 == 1)
            System.out.println("I'm a winner!");
        else
            System.out.println("You're the winner?");
    }

}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class BJ11279 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());

        for (int i=0; i<n; i++){
            int num = Integer.parseInt(br.readLine());
            if (num == 0){
                if (queue.isEmpty())
                    queue.add(0);
                sb.append(queue.poll() + "\n");
            } else{
                queue.add(num);
            }
        }
        System.out.print(sb);
    }
}

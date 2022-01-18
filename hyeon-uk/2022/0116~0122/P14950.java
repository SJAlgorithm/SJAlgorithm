P11509import java.util.*;
class Road implements Comparable<Road>{
    int from,to,cost;

    public Road(int from,int to, int cost) {
        this.from=from;
        this.to=to;
        this.cost = cost;
    }

    @Override
    public int compareTo(Road r){
        return this.cost-r.cost;
    }
}
public class P14950 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, t;

        n = sc.nextInt();
        m = sc.nextInt();
        t = sc.nextInt();

        boolean visited[] = new boolean[n + 1];
        ArrayList<ArrayList<Road>> road = new ArrayList<>();
        for (int i = 0; i <= n; i++) road.add(new ArrayList<Road>());
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int cost = sc.nextInt();
            road.get(u).add(new Road(u, v, cost));
            road.get(v).add(new Road(v, u, cost));
        }

        PriorityQueue<Road> pq = new PriorityQueue<>();

        int sum = 0;
        int gap = 0;

        pq.addAll(road.get(1));
        visited[1] = true;

        while (!pq.isEmpty()) {
            Road r = pq.poll();

            if (!visited[r.to]) {
                if (visited[r.from] && visited[r.to]) continue;
                visited[r.from] = visited[r.to] = true;
                pq.addAll(road.get(r.to));
                sum += (r.cost + gap);
                gap += t;
            }
        }
        System.out.println(sum);
    }
}

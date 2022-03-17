import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P14595 {
    public static class Room{
        int start;
        int end;
        public Room(int start,int end){
            this.start=start;
            this.end=end;
        }
    }

    public static int n,m;
    public static List<Room> rooms=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        m=Integer.parseInt(br.readLine());
        for(int i=0;i<m;i++){
            StringTokenizer st=new StringTokenizer(br.readLine()," ");
            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            rooms.add(new Room(x,y));
        }

        rooms.sort(new Comparator<Room>() {
            @Override
            public int compare(Room o1, Room o2) {
                return o1.start-o2.start;
            }
        });
        if(m==0){
            System.out.println(n);
        }
        else {
            int startRoom = rooms.get(0).start;
            int endRoom = rooms.get(0).end;
            int ret = startRoom;

            for (int i = 1; i < rooms.size(); i++) {
                if(rooms.get(i).start<=endRoom){
                    endRoom=Math.max(endRoom,rooms.get(i).end);
                }
                else{
                    ret+=(rooms.get(i).start-endRoom);
                    startRoom=rooms.get(i).start;
                    endRoom=rooms.get(i).end;
                }
            }
            ret += n - endRoom;
            System.out.println(ret);
        }
    }
}

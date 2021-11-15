import java.util.HashMap;
import java.util.Objects;
class Edge{
    int x,y,nx,ny;

    public Edge(int x, int y, int nx, int ny) {
        this.x = x;
        this.y = y;
        this.nx = nx;
        this.ny = ny;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Edge edge = (Edge) o;
        return x == edge.x && y == edge.y && nx == edge.nx && ny == edge.ny;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, nx, ny);
    }
}
class Point{
    int x,y;
    public Point(int x,int y){
        this.x=x;
        this.y=y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return x == point.x && y == point.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}

class Solution {
    static int mv[][]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    public int solution(int[] arrows) {
        int answer = 0;
        HashMap<Edge,Boolean> edge=new HashMap<>();
        HashMap<Point,Boolean> point=new HashMap<>();
        
        point.put(new Point(0,0),true);
        int x=0;
        int y=0;
        for(int i=0;i<arrows.length;i++){
            int d=arrows[i];
            for(int j=0;j<2;j++){
                int nx=x+mv[d][0];
                int ny=y+mv[d][1];
                Edge dEdge=new Edge(x,y,nx,ny);
                Edge rEdge=new Edge(nx,ny,x,y);
                Point nextPoint=new Point(nx,ny);

                if(point.get(nextPoint)!=null && !(edge.get(dEdge)!=null&&edge.get(rEdge)!=null)){
                    answer++;
                }
                else{
                    point.put(nextPoint,true);
                }
                edge.put(dEdge,true);
                edge.put(rEdge,true);
                x=nx;
                y=ny;
            }
        }
        return answer;
    }
}

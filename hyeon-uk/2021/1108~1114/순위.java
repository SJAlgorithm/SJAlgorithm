import java.util.Arrays;
class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        boolean maze[][]=new boolean[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(maze[i],false);
        }
        for(int i=0;i<results.length;i++){
            int winner=results[i][0];
            int loser=results[i][1];
            maze[winner][loser]=true;
        }
        
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    if(maze[i][k]&&maze[k][j]) maze[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(maze[i][j]||maze[j][i]) cnt++;
            }
            if(cnt==n-1) answer++;
        }
        return answer;
    }
}

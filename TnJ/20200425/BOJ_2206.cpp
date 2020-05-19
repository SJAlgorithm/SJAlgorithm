// <벽 부수고 이동하기> - BOJ_2206
// BFS

#include<bits/stdc++.h>
using namespace std;

int N,M; // 1~1000
int wall[1001][1001];
bool vi[1001][1001][2]={0,};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(int y, int x){
    queue<pair<pair<int,int>,pair<int,int>>> q; // dis,br,y,x
    q.push({{1,0},{y,x}});
    vi[y][x][0] = true;
    vi[y][x][1] = true;

    while(!q.empty()){
        int cdis = q.front().first.first;
        int cbr = q.front().first.second;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();

        if(cy==N && cx==M) return cdis;
        for(int i=0; i<4; i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny<1 || nx<1 || ny>N || nx>M) continue;
            if(wall[ny][nx] && !cbr) {
                int nbr = 1;
                vi[ny][nx][nbr] = true;
                q.push({{cdis+1,nbr},{ny,nx}});
            } else if(!wall[ny][nx] && !vi[ny][nx][cbr]){
                vi[ny][nx][cbr]=true;
                if(cbr==0) vi[ny][nx][1]=true;
                q.push({{cdis+1,cbr},{ny,nx}});
            } 
        }
    }
    return -1;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d",&wall[i][j]);
        }
    }
    int res = bfs(1,1);
    printf("%d",res);

}
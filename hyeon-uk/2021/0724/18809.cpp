#include <algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int maze[50][50]={0};
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,g,r,result=0;
vector<pair<int,int>> soil;

bool isIn(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(){
    int cmaze[50][50];
    int visited[50][50]={0};
    queue<pair<int,int>> red,green;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cmaze[i][j]=maze[i][j];
            if(cmaze[i][j]==3){
                red.push({i,j});
                visited[i][j]=1;
            }
            if(cmaze[i][j]==4){
                green.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    while(true){
        if(red.empty()||green.empty()){
            break;
        }
        int rsize=red.size();
        for(int i=0;i<rsize;i++){
            int x=red.front().first;
            int y=red.front().second;
            int time=visited[x][y];
            red.pop();
            //꽃이기때문에 스킵
            if(cmaze[x][y]==5){
                continue;
            }
            
            for(int j=0;j<4;j++){
                int nx=x+mv[j][0];
                int ny=y+mv[j][1];
                
                if(isIn(nx,ny)&&!visited[nx][ny]&&cmaze[nx][ny]!=0&&(cmaze[nx][ny]==1||cmaze[nx][ny]==2)){
                    cmaze[nx][ny]=3;
                    visited[nx][ny]=time+1;
                    red.push({nx,ny});
                }
            }
        }
        int gsize=green.size();
        for(int i=0;i<gsize;i++){
            int x=green.front().first;
            int y=green.front().second;
            int time=visited[x][y];
            green.pop();
            if(cmaze[x][y]==5){
                continue;
            }
            
            for(int j=0;j<4;j++){
                int nx=x+mv[j][0];
                int ny=y+mv[j][1];
                
                
                if(isIn(nx,ny)&&visited[nx][ny]==time+1&&cmaze[nx][ny]!=0&&cmaze[nx][ny]==3){
                    cmaze[nx][ny]=5;
                }
                else if(isIn(nx,ny)&&!visited[nx][ny]&&cmaze[nx][ny]!=0&&(cmaze[nx][ny]==1||cmaze[nx][ny]==2)){
                    cmaze[nx][ny]=4;
                    visited[nx][ny]=time+1;
                    green.push({nx,ny});
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cmaze[i][j]==5) cnt++;
        }
    }
    result=max(result,cnt);
    return;
}

void dfs(int ind,int rc,int gc){
    if (rc + gc > (soil.size() - ind)) return;
    if (gc == 0 && rc == 0) {
        //배양액을 모두 골랐다면 bfs로 배양액을 뿌려준다.
        bfs();
        return;
    }
    if (ind == soil.size()) return;
    int i=soil[ind].first;
    int j=soil[ind].second;
    
    dfs(ind+1,rc,gc);
    if(rc>0){
        maze[i][j]=3;//빨간색 배양액
        dfs(ind+1,rc-1,gc);
        maze[i][j]=2;
    }
    if(gc>0){
        maze[i][j]=4;//파란색 배양액
        dfs(ind+1,rc,gc-1);
        maze[i][j]=2;
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n>>m>>g>>r;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j]==2) soil.push_back({i,j});
        }
    }
    dfs(0,r,g);
    cout<<result<<"\n";
}

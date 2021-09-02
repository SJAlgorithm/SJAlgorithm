#include <iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 987654321

using namespace std;
typedef pair<int,int> pii;

queue<pii> q;
int n;
int maze[125][125];
int visited[125][125];
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void input_and_init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            visited[i][j]=MAX;
        }
    }

    visited[0][0]=maze[0][0];
}

bool isIn(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}

int bfs(){
    q.push({0,0});
        
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+mv[i][0];
            int ny=y+mv[i][1];

            if(isIn(nx,ny)&&visited[nx][ny]>visited[x][y]+maze[nx][ny]){
                visited[nx][ny]=visited[x][y]+maze[nx][ny];
                q.push({nx,ny});
            }
        }
    }
    return visited[n-1][n-1];
}

int main() {
    int cnt=1;
    while(true){
        cin>>n;
        if(!n){
            break;
        }
        
        input_and_init();
        cout<<"Problem "<<cnt++<<": "<<bfs()<<"\n";
    }
	return 0;
}
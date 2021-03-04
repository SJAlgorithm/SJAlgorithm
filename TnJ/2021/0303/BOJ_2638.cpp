#include<iostream>
#include<queue>
#include<memory.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,M;
int m[101][101]{};
int vi[101][101]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(){
    memset(vi,0,sizeof(vi));
    queue<pii> q;
    q.push({0,0});
    vi[0][0] = true;

    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx]) continue;
            if(m[ny][nx]==0){
                q.push({ny,nx});
                vi[ny][nx] = true;
            }
        }
    }
}

int cheese() {
    int remains = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!m[i][j]) continue;
            int cnt=0;
            for(int k=0; k<4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(vi[ny][nx]) cnt++;
            }
            if(cnt>1) m[i][j] = 0;
            else remains++;
        }
    }
    return remains;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>m[i][j];
        }
    }

    int cnt = 0;
    while(1){
        bfs();
        int sum = cheese();
        cnt++;
        if(sum==0) break;
    }
    
    cout<<cnt;
}
#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,M,cnt;
int m[101][71]{};
bool vi[101][71]{};
int dy[8] = {-1,1,0,0,-1,-1,1,1};
int dx[8] = {0,0,-1,1,-1,1,-1,1};

void bfs(int sty, int stx, int h){
    memset(vi,0,sizeof(vi));
    queue<pii> q;
    q.push({sty,stx});
    vi[sty][stx] = true;

    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();

        for(int i=0; i<8; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx] || m[ny][nx]==0) continue;
            if(m[ny][nx]>h || m[ny][nx]==-1) return;
            if(m[ny][nx]==h) {
                q.push({ny,nx});
            }
            vi[ny][nx] = true;
        }
    }

    m[sty][stx] = -1;
    cnt++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>m[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(m[i][j]==0) continue;
            bfs(i,j,m[i][j]);
        }
    }

    cout<<cnt;
}
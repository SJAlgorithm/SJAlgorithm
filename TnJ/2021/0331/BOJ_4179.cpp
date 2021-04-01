#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N,M, sty, stx;
char m[1001][1001]{};
bool vi[1001][1001]{};
int dp[1001][1001][2]{}; // 0: Ji, 1: Fire
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

struct Info{
    int d,y,x;
    Info(int d_=0, int y_=0, int x_=0) :d(d_), y(y_), x(x_){}
};

void bfs(int chk){
    memset(vi,0,sizeof(vi));
    queue<Info> q;
    if(chk) {
        for(int i=0; i<N; i++) 
            for(int j=0; j<M; j++) 
                if(m[i][j]=='F') {
                    q.push(Info(0,i,j));
                    dp[i][j][chk] = 0;
                    vi[i][j]=true;
                }
    }
    else {
        q.push(Info(0,sty,stx));
        dp[sty][stx][chk] = 0;
        vi[sty][stx] = true;
    }

    while(!q.empty()){
        int cd = q.front().d;
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nd = cd + 1;
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(vi[ny][nx] || m[ny][nx]=='#') continue;
            q.push(Info(nd, ny, nx));
            dp[ny][nx][chk] = nd;
            vi[ny][nx] = true;
        }

    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    string str;
    for(int i=0; i<N; i++) {
        cin>>str;
        for(int j=0; j<M; j++){
            m[i][j] = str[j];
            if(m[i][j]=='J') sty = i, stx = j;
        }
    }

    memset(dp,0x3f,sizeof(dp));
    bfs(0);
    bfs(1);

    int res = INF;
    for(int i=0; i<N; i++){
        if(m[i][0]=='#') continue;
        if(dp[i][0][0] < dp[i][0][1]) res = min(res, dp[i][0][0]);
    }
    for(int i=0; i<N; i++){
        if(m[i][M-1]=='#') continue;
        if(dp[i][M-1][0] < dp[i][M-1][1]) res = min(res, dp[i][M-1][0]);
    }
    for(int j=0; j<M; j++){
        if(m[0][j]=='#') continue;
        if(dp[0][j][0] < dp[0][j][1]) res = min(res, dp[0][j][0]);
    }
    for(int j=0; j<M; j++){
        if(m[N-1][j]=='#') continue;
        if(dp[N-1][j][0] < dp[N-1][j][1]) res = min(res, dp[N-1][j][0]);
    }

    if(res==INF) cout<<"IMPOSSIBLE";
    else cout<<res+1;
}

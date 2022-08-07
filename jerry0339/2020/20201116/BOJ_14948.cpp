// <군대 탈출하기> - BOJ_14948
// 우선순위 큐 + (bfs, rbfs) 이용

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 0x3f3f3f3f;

int N,M;
int m[102][102]{};
int d[102][102]{};
int d1[102][102]{};
int d2[102][102]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void solve(int sty, int stx){
    priority_queue<piii> q;
    q.push({-m[sty][stx],{sty,stx}});
    d[sty][stx] = m[sty][stx];

    while(!q.empty()){
        int clv = -q.top().xx;
        int cy = q.top().yy.xx;
        int cx = q.top().yy.yy;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            int nlv = max(clv,m[ny][nx]);
            if(d[ny][nx]>nlv){
                q.push({-nlv,{ny,nx}});
                d[ny][nx] = nlv;
            }
        }
    }
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
    memset(d,0x3f,sizeof(d));
    solve(0,0);
    memcpy(d1, d, sizeof(d));

    memset(d,0x3f,sizeof(d));
    solve(N-1,M-1);
    memcpy(d2, d, sizeof(d));

    int x,y,a,b,ans=INF;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            x = INF;
            y = INF;
            if(i>0 && i<N-1) {
                a = max(d1[i-1][j],d2[i+1][j]);
                b = max(d1[i+1][j],d2[i-1][j]);
                x = min({a,b});
            }
            if(j>0 && j<M-1) {
                a = max(d1[i][j-1],d2[i][j+1]);
                b = max(d1[i][j+1],d2[i][j-1]);
                y = min({a,b});
            }
            d[i][j] = max(d1[i][j],d2[i][j]);
            d[i][j] = min({d[i][j],x,y});
            ans = min(ans,d[i][j]);
        }
    }
    cout<<ans;
}
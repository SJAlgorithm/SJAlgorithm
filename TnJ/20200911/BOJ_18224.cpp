// <미로에 갖힌 건우> - BOJ_18224
// BFS, DP(4차원)

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int N,M;
int m[501][501]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool vi[501][501][10][2]{}; // y, x, Mth Move, sun&moon

int solve(){
    queue<piii> q;
    q.push({0,{0,0}});
    vi[0][0][0][0] = 0;

    while(!q.empty()){
        int cd = q.front().xx;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        if(cy==N-1 && cx==N-1) return cd;

        for(int i=0; i<4; i++){
            int nd = cd + 1;
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny<0 || nx<0 || ny>=N || nx>=N || vi[ny][nx][nd%M][nd/M%2]) continue;
            if(m[ny][nx]==1) {
                if((cd/M)%2 == 0) continue;
                bool chk = false;
                while(m[ny][nx]){
                    ny += dy[i];
                    nx += dx[i];
                    if(ny<0 || nx<0 || ny>=N || nx>=N) {chk = true; break;}
                }
                if(chk || vi[ny][nx][nd%M][nd/M%2]) continue;
            }
            q.push({nd,{ny,nx}});
            vi[ny][nx][nd%M][nd/M%2] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>m[i][j];
    
    int res = solve();
    if(res == -1) {cout<<-1; return 0;}
    cout<<res/(M*2) + 1<<' ';
    if((res/M)%2) cout<<"moon";
    else cout<<"sun";
}
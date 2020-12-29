// <달이 차오른다, 가자.> - BOJ_1194
// Bitmask , BFS

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,M,sty,stx;
char m[51][51]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool vi[51][51][1<<6]{};

int solve(){
    queue<pair<pii,pii>> q; // (dis, key), (y,x)
    q.push({{0,0},{sty,stx}});
    vi[sty][stx][0] = true;

    while(!q.empty()){
        int cd = q.front().xx.xx;
        int ck = q.front().xx.yy;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        if(m[cy][cx] == '1') return cd;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nd = cd + 1;
            if(ny<0 || nx<0 || ny>=N || nx>=M || m[ny][nx]=='#'|| vi[ny][nx][ck]) continue;
            char nm = m[ny][nx];
            int nk = ck;
            if((nm>='A' && nm<='F') && (ck&(1<<(nm-'A')))==0) continue;
            if(nm>='a' && nm<='f') nk |= (1<<(nm-'a'));
            q.push({{nd,nk},{ny,nx}});
            vi[ny][nx][nk] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) {
            cin>>m[i][j]; 
            if(m[i][j]=='0') {sty = i; stx = j;}
        }

    cout<<solve();
}
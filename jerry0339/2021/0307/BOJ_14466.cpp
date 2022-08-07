#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,K,R;
bool road[101][101][4]{};
bool m[101][101]{};
bool vi[101][101]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(int sty, int stx){
    queue<pii> q;
    q.push({sty,stx});
    vi[sty][stx] = true;
    int res = 1;

    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();

        for(int i=0; i<4; i++){
            if(road[cy][cx][i]) continue;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<=0 || nx<=0 || ny>N || nx>N || vi[ny][nx]) continue;
            q.push({ny,nx});
            vi[ny][nx] = true;
            if(m[ny][nx]) res++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>R;
    int a,b,x,y;
    for(int i=0; i<R; i++) {
        cin>>b>>a>>y>>x;
        int t1 = y-b;
        int t2 = x-a;
        if(t1==0){
            if(t2==1) {road[b][a][3] = true; road[y][x][2] = true;}
            else {road[b][a][2] = true; road[y][x][3] = true;}
        } else {
            if(t1==1) {road[b][a][1] = true; road[y][x][0] = true;}
            else {road[b][a][0] = true; road[y][x][1] = true;}
        }
    }
    queue<pii> q;
    for(int i=0; i<K; i++) {
        cin>>a>>b;
        m[a][b] = true;
        q.push({a,b});
    }

    int ans=0, sum=0, tmp;
    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();
        if(vi[cy][cx]) continue;
        tmp = bfs(cy, cx);
        ans += (sum*tmp);
        sum += tmp;
    }

    cout<<ans;
}
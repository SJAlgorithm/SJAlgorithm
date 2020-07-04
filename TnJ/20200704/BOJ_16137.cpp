// <견우와 직녀> - BOJ_16137
// priority_queue, bfs, DP, Implement

#include<bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef pair<int,int> pii;

int N,P;
int m[11][11]{};
bool vi[2][11][11]{};
vector<pii> v;
int dy[5] = {-1,0,1,0,-1};
int dx[5] = {0,1,0,-1,0};
struct Info{
    int d,b,y,x; // distance, bridge, y,x
    Info(int d_=0, int b_=0, int y_=0, int x_=0) :d(d_), b(b_), y(y_), x(x_){}
};

struct comp{
    bool operator()(Info &a, Info &b){
        return a.d > b.d;
    }
};

bool ispossible(int y, int x){
    int ny1, nx1, ny2, nx2;
    for(int i=0; i<4; i++){
        ny1 = y+dy[i];   nx1 = x+dx[i];
        ny2 = y+dy[i+1]; nx2 = x+dx[i+1];
        if(ny1<0 || nx1<0 || ny1>=N || nx1>=N) continue;
        if(ny2<0 || nx2<0 || ny2>=N || nx2>=N) continue;
        if(m[ny1][nx1]!=1 && m[ny2][nx2]!=1) return false;
    }
    return true;
}

void solve(){
    priority_queue<Info, vector<Info>, comp> pq;
    pq.push(Info(0,0,0,0));
    vi[0][0][0]=true;
    
    while(!pq.empty()){
        int cd = pq.top().d;
        int cb = pq.top().b;
        int cy = pq.top().y;
        int cx = pq.top().x;
        pq.pop();

        if(cy==N-1 && cx==N-1) { cout<<cd; exit(0);}

        int ny, nx, nd;
        for(int i=0; i<4; i++){
            ny = cy + dy[i];
            nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N || vi[cb][ny][nx] || m[ny][nx]==-1) continue;
            if(m[ny][nx]==1) {
                pq.push(Info(cd+1,cb,ny,nx));
                vi[cb][ny][nx] = true;
                continue;
            }
            if(m[ny][nx]==0) {
                if(cb) continue;
                if(m[cy][cx]>1) continue;
                if((cd+1)%P==0) nd = cd+1;
                else {
                    nd = cd/P + 1;
                    nd *= P;
                }
                pq.push(Info(nd,1,ny,nx));
                vi[1][ny][nx] = true;
            } else { // m[ny][nx] > 1
                if(m[cy][cx]!=1) continue;
                if( ((cd+1)%m[ny][nx]) == 0) nd = cd+1;
                else {
                    nd = cd/m[ny][nx] + 1;
                    nd *= m[ny][nx];
                }
                pq.push(Info(nd,cb,ny,nx));
                vi[cb][ny][nx] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>P;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
            if(m[i][j]==0){
                v.push_back({i,j});
            }
        }
    }
    
    for(int i=0; i<v.size(); i++){
        int y = v[i].xx;
        int x = v[i].yy;
        if(!ispossible(y,x))
            m[y][x] = -1;
    }

    solve();
}

/*
3 10
1 100 0
1 0 100
0 1 1

3 5
1 0 1
0 6 10
0 1 1

*/
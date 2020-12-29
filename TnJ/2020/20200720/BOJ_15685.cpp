#include<bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef pair<int,int> pii;

int N,x,y,d,g;
int m[101][101]{};
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0}; // 0<=y<=3
vector<pii> v;

bool chkRec(int y, int x){
    if(!m[y+1][x]) return false;
    if(!m[y][x+1]) return false;
    if(!m[y+1][x+1]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(N--){
        cin>>x>>y>>d>>g;
        v.clear();
        m[y][x] = 1;
        m[y+dy[d]][x+dx[d]] = 1;
        v.push_back({y,x});
        v.push_back({y+dy[d],x+dx[d]});
        
        int sty, stx, n, ndy, ndx, ny, nx;
        for(int i=0; i<g; i++){
            sty = v.back().xx;
            stx = v.back().yy;
            n = v.size();
            for(int j=n-2; j>=0; j--){
                ndy = stx - v[j].yy;
                ndx = sty - v[j].xx;
                ndy*=-1;
                ny = sty + ndy;
                nx = stx + ndx;
                if(ny<0 || nx<0 || ny>100 || nx>100) continue;
                m[ny][nx] = 1;
                v.push_back({ny,nx});
            }
        }
    }
    int cnt=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(m[i][j] && chkRec(i,j)) {
                cnt++;
            }
        }
    }

    cout<<cnt;
}
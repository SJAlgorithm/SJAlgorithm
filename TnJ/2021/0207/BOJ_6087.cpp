#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<pii,pii> piiii;
const int INF = 0x3f3f3f3f;

char m[101][101]{};
int vi[101][101]{};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};
int N,M, sty, stx, edy, edx;;

struct comp{
    bool operator()(piiii a, piiii b){
        return a.yy.xx > b.yy.xx;
    }
};

int bfs(int sty, int stx){
    priority_queue<piiii, vector<piiii>, comp> pq;
    pq.push({{sty,stx},{0,-1}}); // y, x, dist, dir
    vi[sty][stx] = 0;
    m[sty][stx] = '.';

    while(!pq.empty()){
        int cy = pq.top().xx.xx;
        int cx = pq.top().xx.yy;
        int cdis = pq.top().yy.xx;
        int cdir = pq.top().yy.yy;
        pq.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int ndis = cdis;
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(m[ny][nx]=='*') continue;
            if(i!=cdir) ndis++;
            if(ndis <= vi[ny][nx]){
                pq.push({{ny,nx},{ndis,i}});
                vi[ny][nx] = ndis;
            }
        }
    }

    return vi[edy][edx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    memset(vi,0x3f,sizeof(vi));

    string str;
    sty=-1, stx=-1;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            m[i][j] = str[j];
            if(m[i][j] == 'C') {
                if(sty==-1 && stx==-1) {sty = i; stx = j;}
                else {edy = i; edx = j;}
            }
        }
    }

    cout<<bfs(sty, stx)-1<<'\n';
}
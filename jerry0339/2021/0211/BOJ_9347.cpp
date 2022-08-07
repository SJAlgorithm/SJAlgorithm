/*
1
9 7
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 0 1 0 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 0 1 0 1 1
1 1 1 1 1 1 1
답이 왜 2 6 임...?
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 0x3f3f3f3f;

int T,N,M;
int m[1001][1001]{};
int d[1001][1001]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int res[1001]{};

void dijk(){
    priority_queue<piii> pq;
    for(int j=0; j<M; j++) {
        if(m[0][j]) d[0][j] = 1;
        else d[0][j] = 0;
        pq.push({-d[0][j],{0,j}});

        if(m[N-1][j]) d[N-1][j] = 1;
        else d[N-1][j] = 0;
        pq.push({-d[N-1][j],{N-1,j}});
    }
    for(int i=1; i<N-1; i++) {
        if(m[i][0]) d[i][0] = 1;
        else d[i][0] = 0;
        pq.push({-d[i][0],{i,0}});
        
        if(m[i][M-1]) d[i][M-1] = 1;
        else d[i][M-1] = 0;
        pq.push({-d[i][M-1],{i,M-1}});
    }
    
    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cy = pq.top().yy.xx;
        int cx = pq.top().yy.yy;
        pq.pop();

        if(d[cy][cx] < cd) continue;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nd = cd;
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(m[ny][nx]) nd++;
            if(nd < d[ny][nx]){
                d[ny][nx] = nd;
                pq.push({-nd,{ny,nx}});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>M;
        memset(d,0x3f,sizeof(d));
        memset(res,0,sizeof(res));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>m[i][j];
            }
        }

        dijk();
        int k = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(m[i][j]==0){
                    res[d[i][j]]++;
                    k = max(k, d[i][j]);
                }
            }
        }
        
        cout<<k<<' '<<res[k]<<'\n';
    }
    
}
// <연구소2> - BOJ_17141
// BFS, DFS

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

// 0: 빈칸, 1: 벽, 2: 바이러스
int min_ = INF;
int N,M; // 5<=N<=50, 1<=M<=10
int m[52][52];
int cpym[52][52]={0,};
vector<pair<int,int>> adj;
bool vi[52][52]={false,};
bool viCpy[52][52]={false,};
deque<pair<int,int>> gq;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(){
    deque<pair<int,int>> q = gq;
    memcpy(viCpy,vi,sizeof(vi));
    memset(cpym,0,sizeof(cpym));
    
    int max_ = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop_front();
        for(int i=0; i<4; i++){
            int nexty = y+dy[i];
            int nextx = x+dx[i];
            if(nexty<1 || nexty>N || nextx<1 || nextx > N ) continue;
            if(!viCpy[nexty][nextx]) {
                cpym[nexty][nextx] = cpym[y][x]+1;
                viCpy[nexty][nextx] = true;
                q.push_back({nexty,nextx});
                max_ = max(max_,cpym[nexty][nextx]);
            }
        }
    }
    bool chk = true;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            if(!viCpy[i][j]) chk=false;
        }
        if(!chk) break;
    }
    if(chk) min_ = min(max_,min_);
}

void searchVirus(int depth, int c){ // dfs
    if(depth==M){
        bfs();
    }

    for(int i=c; i<adj.size(); i++){
        if(!vi[adj[i].first][adj[i].second]) {
            vi[adj[i].first][adj[i].second] = true;
            gq.push_back({adj[i].first, adj[i].second});
            searchVirus(depth+1,i+1);
            vi[adj[i].first][adj[i].second] = false;
            gq.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>m[i][j];
            if(m[i][j]==1) vi[i][j] = true;
            if(m[i][j]==2) adj.push_back({i,j}); 
        }
    }

    searchVirus(0,0);
    if(min_==INF) {cout<<"-1"; return 0;}
    cout<<min_;
}
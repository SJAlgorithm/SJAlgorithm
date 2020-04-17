// <연구소> - BOJ_14502
// DFS + BFS

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, maxV = 0;
int rsMap[8][8] = { 0, };
int cpyMap[8][8];
bool vi[8][8] = { false, };
queue<pii> q;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

void countSafe(){
    queue<pii> cq = q;
    memset(vi,false,sizeof(vi));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cpyMap[i][j] = rsMap[i][j];
        }
    }

    int y,x;
    while(!cq.empty()){
        y = cq.front().first;
        x = cq.front().second;
        cq.pop();
        for(int i=0; i<4; i++){
            int b=y+dy[i];
            int a=x+dx[i];
            if(b<0 || b>=N || a<0 || a>=M) continue;
            if(!cpyMap[b][a]) {
                cpyMap[b][a] = 2;
                cq.push({b,a});
            }
        }
    }
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!cpyMap[i][j]) cnt++;
        }
    }
    if(cnt > maxV) maxV = cnt;
}

void searchWall(int depth, int idx) {
    if (depth == 3) {
        countSafe();
        return;
    }

    for (int i = idx; i < N * M; i++) {
        if(!rsMap[i/M][i%M]) {
            rsMap[i/M][i%M]=1;
            searchWall(depth + 1, i + 1);
            rsMap[i/M][i%M]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> rsMap[i][j];
            if(rsMap[i][j]==2) {
                //vi[i][j]==true;
                q.push({i,j});
            }
        }
    }

    searchWall(0, 0);
    cout << maxV;
}
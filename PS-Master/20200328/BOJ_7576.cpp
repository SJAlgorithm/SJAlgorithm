// <토마토> - BOJ_7576
// BFS , B&B

#include<bits/stdc++.h>
using namespace std;

int M,N,cnt=0,chk=0,chk2=0;
int tmt[1001][1001]={0,};
queue<pair<int,int>> q;

bool isPossible(int i, int j){
    if(i<0 || i>=N || j<0 || j>=M) return false;
    return true;
}

void bfs(){
    // up down left right
    int dy[4] = {-1,1,0,0}; 
    int dx[4] = {0,0,-1,1};
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop(); 
        chk2++;

        for(int i=0; i<4; i++){
            int b = y+dy[i];
            int a = x+dx[i];
            if(isPossible(b,a) && !tmt[b][a]){
                tmt[b][a]=1;
                q.push(make_pair(b,a));
            }
        }

        if(chk2==chk){
            cnt++;
            chk = q.size();
            chk2 = 0;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            int n; cin>>n;
            tmt[i][j] = n;
            if(n==1) {
                q.push(make_pair(i,j));
                chk++;
            }
        }
    }

    bfs();
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            if(!tmt[i][j]) {
                cout<<"-1";
                exit(0);
            }
            
        }
    }
    cout<<cnt-1;
}
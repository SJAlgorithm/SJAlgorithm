// <뱀과 사다리 게임> - BOJ_16928
// BFS

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int m[110]={0,0,};
int item[101]={0,};
int vi[101]={0,1};

void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int next = cur+i;
            if(next > 100) continue;
            if(item[next]){
                next = item[next];
            }
            if(m[next]==INF){
                m[next] = m[cur]+1;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M; cin>>N>>M;
    int t;
    for(int i=2; i<=100; i++) m[i]=INF;
    for(int i=0; i<N+M; i++) {
        cin>>t;
        cin>>item[t];
    }
    
    bfs(1);
    cout<<m[100];
}

// <숨바꼭질3> - BOJ_13549
// BFS

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;

int N,K; // 0~100,000
int vi[MAX+1]={0,};
int dis[MAX+1]={0,};

int bfs(int start){
    queue<int> q;
    q.push(start);
    int next;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == K) return dis[K];
        if(cur*2<=MAX && !vi[cur*2]){ // *2
            next = cur*2;
            q.push(next);
            vi[next] = true;
            dis[next] = dis[cur];
        }
        if(cur+1<=MAX && !vi[cur+1]){ // +1
            next = cur+1;
            q.push(next);
            vi[next] = true;
            dis[next] = dis[cur]+1;
        }
        if(cur-1>=0 && !vi[cur-1]){
            next = cur-1;
            q.push(next);
            vi[next] = true;
            dis[next] = dis[cur]+1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    cout<<bfs(N);
}
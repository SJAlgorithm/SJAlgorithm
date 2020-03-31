// <숨바꼭질> - BOJ_1697
// BFS

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;

int N,K;
bool vi[100001]={false,};


int bfs(int st){
    queue<pair<int,int>> q;
    q.push({st,0});
    vi[st]=true;
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == K) return cnt;

        if(cur-1 >= 0 && !vi[cur-1]) {
            q.push({cur-1, cnt+1});
            vi[cur-1] = true;
        }
        if(cur+1 <= MAX && !vi[cur+1]) {
            q.push({cur+1, cnt+1});
            vi[cur+1] = true;
        }
        if(cur*2 <= MAX && !vi[cur*2]){
            q.push({cur*2, cnt+1});
            vi[cur*2] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    cout<<bfs(N);
}
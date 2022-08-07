// <N과 M(2)> - BOJ_15650
// 백트래킹

#include<bits/stdc++.h>
using namespace std;

int n,m;
char res[22];

void dfs(int depth, int p) {
    if(depth == m){
        cout<<res<<'\n';
        return;
    }
    for(int i=p+1; i<=n; i++){ // 가지치기 : 전에 방문한 수 보다 큰 수만 방문
        res[depth*2] = i+'0';
        res[depth*2 + 1] = ' ';
        dfs(depth+1,i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    dfs(0,0);
}
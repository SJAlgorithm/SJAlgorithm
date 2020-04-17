// <퇴사> - BOJ_14501
// DFS로 풀음.
// DP코드로 공부 ㄱㄱ

#include<bits/stdc++.h>
using namespace std;

int maxC,n,cnt=0;
vector<pair<int,int>> v; // <시간,금액>

void dfs(int depth){
    cnt += v[depth].second;
    if(cnt > maxC) maxC = cnt;
    for(int i=v[depth].first + depth; i<=n; i++) {
        if(v[i].first + i <= n+1) {
            dfs(i);
            cnt -= v[i].second;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    v.push_back(make_pair(1,0));
    for(int i=1; i<=n; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    dfs(0);
    cout<<maxC;
}
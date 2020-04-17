// <퇴사2> - BOJ_15486

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N,nextD;
int dp[1500051] ={0,};
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N+1);

    for(int i=1; i<=N; i++)
        cin>>v[i].first>>v[i].second;

    for(int i=1; i<=N; i++){
        nextD = v[i].first+i;
        dp[nextD] = max(dp[nextD],dp[i]+v[i].second);
        dp[i+1] = max(dp[i+1],dp[i]);
    }

    cout<<dp[N+1];
}
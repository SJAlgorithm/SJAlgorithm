// <1,2,3 더하기 4> - BOJ_15989
// DP

#include<bits/stdc++.h>
using namespace std;

int dp[4][10005]={0,};
int T,maxn=0;
vector<int> t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    int n;
    while(T--){
        cin>>n;
        t.push_back(n);
        maxn = max(n,maxn);
    }
    for(int j=0; j<=maxn; j++) dp[1][j] = 1;
    dp[2][2] = 1;
    for(int j=3; j<=maxn; j++){
        dp[2][j] = dp[1][j-2] + dp[2][j-2];
        dp[3][j] = dp[1][j-3] + dp[2][j-3] + dp[3][j-3];
    }
    for(auto val : t) cout<<dp[1][val]+dp[2][val]+dp[3][val]<<'\n';

}
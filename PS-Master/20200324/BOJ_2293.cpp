// <동전1> - BOJ_2293
// DP

#include<bits/stdc++.h>
using namespace std;

int n,k;
int coin[101];
int dp[10001]={0,}; // k원 만들 수 있는 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=coin[i]; j<= k; j++){
            dp[j] += dp[j - coin[i]];
        }  
    }

    cout<<dp[k];
}
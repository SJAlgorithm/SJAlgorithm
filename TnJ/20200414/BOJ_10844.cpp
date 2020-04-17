// <쉬운 계단 수> - BOJ_10844
// DP

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9;

int dp[104][12]={0,};
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int j=2; j<=10; j++) dp[1][j] = 1;
    for(int i=2; i<=N; i++){
        for(int j=1; j<=10; j++){
            dp[i][j-1] = (dp[i][j-1] + dp[i-1][j])%MOD;
            dp[i][j+1] = (dp[i][j+1] + dp[i-1][j])%MOD;
        }
    }
    
    int sum=0;
    for(int j=1; j<=10; j++) sum = (sum + dp[N][j])%MOD;
    cout<<sum;
}
// <계단 수> BOJ_1562
// 비트마스킹, DP(바텀 업)

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9;

int dp[101][12][1<<10]{};
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // index 1: 숫자0, index 10: 숫자9
    // N 15~16
    cin>>N;
    if(N<10) {cout<<0; return 0;}
    
    for(int j=2; j<=10; j++) dp[1][j][1<<(j-1)] = 1;

    for(int i=2; i<=N; i++){
        for(int j=1; j<=10; j++){
            for(int k=0; k<(1<<10); k++){
                dp[i][j][k|(1<<(j-1))] = (dp[i][j][k|(1<<(j-1))] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
                //dp[i][j][k|(1 << (j-1))] = (dp[i][j][k | (1 << (j-1))] + dp[i - 1][j - 1][k]) % MOD;
                //dp[i][j][k|(1 << (j-1))] = (dp[i][j][k | (1 << (j-1))] + dp[i - 1][j + 1][k]) % MOD;
            }
        }
    }

    int sum=0;
    for(int j=1; j<=10; j++) sum = (sum + dp[N][j][(1<<10)-1])%MOD;
    cout<<sum;
}
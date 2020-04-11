// <합분해> - BOJ_2225
// DP - 쉬웠음

#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9;

int dp[201][201] ={0,};
int N,K,cnt=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int j=0; j<=N; j++) dp[1][j] = 1;
    for(int i=2; i<=K; i++){ // K개
        for(int j=0; j<=N; j++){ // 만들 수
            for(int k=0; k<=j; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
            }
        }
    }
    cout<<dp[K][N];
}
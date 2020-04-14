#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int N;
long dp[104][14];    // dp[i][N]: N으로 시작하는 길이 i의 계단 수
long ret;

int main() {
    int mod = 1000000000;
    scanf("%d", &N);
    
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][1];
        for (int j = 1; j < 10; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    
    for (int i = 0; i < 10; i++) ret += dp[N][i];
    printf("%ld\n", ret%mod);
    
    return 0;
}


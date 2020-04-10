#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, K;
int cnt = 0;
long dp[204][204]; // dp[N][i]: i개의 숫자로 N을 만드는 경우
int mod = 1000000000;

int main() {
    scanf("%d %d", &N, &K);
    
    if (K == 1) dp[N][K] = 1;
    else if (K == 2) dp[N][K] = N+1;
    
    else {
        for (int i = 0; i < 204; i++) {
            if (i != 0) dp[0][i] = 1;
            dp[i][0] = 0;
            dp[i][1] = 1;
            dp[i][2] = i+1;
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 3; j <= K; j++) {
                for (int k = 0; k <= i; k++) {
                    dp[i][j] += dp[k][j-1];
                }
                dp[i][j] %= mod;
            }
        }
    }
    printf("%ld\n", dp[N][K]);
    return 0;
}


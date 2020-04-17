#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int N;
long dp[104];
long ret;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i <= 6; i++) dp[i] = i;
    
    for (int i = 7; i <= N; i++) {
        int k = 4;
        for (int j = i-5; j <= i-3; j++) {
            ret = dp[j]*k;
            dp[i] = max(dp[i], ret);
            k--;
        }
        printf("dp[%d] = %ld\n", i, dp[i]);
    }
    
    printf("%ld\n", dp[N]);
    return 0;
}


#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N;
int dp[10004][3];

// dp[i][0]: 1로 시작하는 경우
// dp[i][1]: 2로 시작하는 경우
// dp[i][2]: 3으로 시작하는 경우

int main() {
    int t;
    scanf("%d", &N);
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    
    for (int i = 4; i < 10001; i++) {
        dp[i][0] = 1;
        dp[i][1] = dp[i-2][0] + dp[i-2][1];
        dp[i][2] = dp[i-3][0] + dp[i-3][1] + dp[i-3][2];
    }
    
    while (N--) {
        scanf("%d", &t);
        printf("%d\n", dp[t][0]+dp[t][1]+dp[t][2]);
    }
    
    return 0;
}


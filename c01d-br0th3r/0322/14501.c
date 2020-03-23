#include <stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int N;
    int T[17], P[17];
    int i, answer = 0;
    int dp[17] = { 0 }; // dp[i] 는 i번째 날에 받을 수 있는 최대 금액
    
    scanf("%d", &N);
    
    for (i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }
    
    for (i = 1; i <= N; i++) {
        
        // i 번째 날에 일을 함
        if (i + T[i] <= N + 1) {
            // i + T[i]날 받을 수 있는 최댓값 갱신
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
            
            answer = max(answer, dp[i + T[i]]);
        }
        
        // i 번째 날에 일을 안 함
        dp[i + 1] = max(dp[i], dp[i + 1]);
        
        answer = max(answer, dp[i + 1]);
    }
    
    printf("%d\n", answer);
    
    return 0;
}


#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int N, K;
char answer[34];
bool dp[34][34][34][436];

bool go(int n, int a, int b, int k) {
    if (n == N) {
        if (k == K) return true;
        else return false;
    }
    
    if (dp[n][a][b][k]) {
        return false;
    }
    
    dp[n][a][b][k] = true;
    
    answer[n] = 'A';
    if (go(n+1, a+1, b, k)) return true;
    
    answer[n] = 'B';
    if (go(n+1, a, b+1, k+a)) return true;
    
    answer[n] = 'C';
    if (go(n+1, a, b, k+a+b)) return true;
    
    return false;
    
}

int main() {
    scanf("%d %d", &N, &K);
    
    go(0, 0, 0, 0) ? printf("%s\n", answer) : printf("-1\n");
    return 0;
}


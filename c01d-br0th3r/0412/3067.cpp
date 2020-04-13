#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int T, N, M;
int dp[10004];
int arr[24];
int ret;

void init() {
    for (int i = 0; i < 24; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < 10004; i++) {
        dp[i] = 0;
    }
}

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &M);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = arr[i]; j <= M; j++) {
                dp[j] += dp[j-arr[i]];
            }
        }
        printf("%d\n", dp[M]);
    }
    return 0;
}


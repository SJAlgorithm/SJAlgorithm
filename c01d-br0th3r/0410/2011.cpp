#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

char d[5004];
int dp[5004];
int cnt;
int flag = 0;

int main() {
    scanf("%s", d);
    
    dp[0] = 1;
    dp[1] = 1;
    
    if (d[0] == '0') flag = 1;
    
    for (int i = 0; i < strlen(d) - 1; i++) {
        if (d[i] == '0') {
            if (d[i+1] == '0') flag = 1;
        }
    }
    
    for (int i = 2; i <= strlen(d); i++) {
        int now = (d[i-2]-'0')*10 + (d[i-1]-'0');
        if ((now >= 1 && now <= 26 && (d[i-2]-'0') != 0)) {
            if (now == 10 || now == 20) dp[i] += dp[i-2];
            else dp[i] = dp[i-2] + dp[i-1];
        }
        else {
            if (now % 10 == 0) flag = 1;
            dp[i] = dp[i-1];
        }
        dp[i] %= 1000000;
    }
    cnt = flag ? 0 : dp[strlen(d)];
    printf("%d\n", cnt);
    return 0;
}


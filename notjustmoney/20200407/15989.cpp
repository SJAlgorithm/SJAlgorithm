// "1,2,3 ¥ı«œ±‚ 4", https://www.acmicpc.net/problem/15989
// writen in C++
// 2020. 04.09
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int dp[2][10004];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(dp, 0, sizeof(dp));
		int n;
		scanf("%d", &n);
		dp[0][2] = 1;
		for(int i=3; i<=n; i++) {
			dp[0][i]=dp[0][i-2]+1;
			dp[1][i]=dp[0][i-3]+dp[1][i-3]+1;
		}
	printf("%d\n", dp[0][n]+dp[1][n]+1);
	}
}

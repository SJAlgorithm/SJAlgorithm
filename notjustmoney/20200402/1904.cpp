// "01≈∏¿œ", https://www.acmicpc.net/problem/1904
// writen in C++
// 2020. 04.04
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int dp[1000004];
int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 1; dp[2] = 2;	
	for(int i = 3; i <= n; i++) {
		dp[i] = dp[i-1]+dp[i-2];
		dp[i] %= 15746;	
	}
	printf("%d\n", dp[n]);
	return 0;
}

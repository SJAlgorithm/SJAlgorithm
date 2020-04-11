// "ÇÕºÐÇØ", https://www.acmicpc.net/problem/2225
// writen in C++
// 2020. 04.09
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int dp[204][204];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i<=n; i++) {
		dp[1][i]=1;
	}
	for(int i=1; i<=k; i++) {
		for(int j=0; j<=n; j++) {
			for(int l=0; l<=j; l++) {
				dp[i][j] += dp[i-1][j-l];
				dp[i][j] %= 1000000000;
			}
		}
	}
	printf("%d\n", dp[k][n]);
	return 0;	
}

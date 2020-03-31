// "플로이드", https://www.acmicpc.net/problem/11404
// writen in C++
// 2020. 03. 29
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int g[105][105];
int dp[105][105];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) memset(dp[i], 1, sizeof(int)*(n+1));
	const int INF = dp[1][1];
	
	for(int i = 0; i < m; i++) {
		int n1, n2, c;
		scanf("%d %d %d", &n1, &n2, &c);
		if(dp[n1][n2] > c) dp[n1][n2] = c;
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dp[i][k] != INF || dp[k][j] != INF)
				if(dp[i][j] > dp[i][k]+dp[k][j])
					dp[i][j] = dp[i][k]+dp[k][j];
			}
		}
	}
	
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
			if(i==j || dp[i][j] == INF) dp[i][j] = 0;
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int miro[1001][1001];
int dp[1001][1001];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
	for(int j = 1; j <= m; j++) 
		scanf("%d", &miro[i][j]);
		
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			dp[i][j] += miro[i][j];
		}
	}
	printf("%d\n", dp[n][m]);
	
	return 0;	
}

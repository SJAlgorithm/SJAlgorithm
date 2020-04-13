// "Επ»η2", https://www.acmicpc.net/problem/15486
// writen in C++
// 2020. 04.07
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int dp[1500004];
int main() {
	int n;
	int ans=0;
	scanf("%d", &n);
	for(int i=1; i<=n+1; i++) {
		ans = max(ans, dp[i]);
		if(i == n+1) break;
		int day, pay;
		scanf("%d %d", &day, &pay);
		if(i+day > n+1) continue;
		dp[i+day] = max(ans+pay, dp[i+day]);
	}
	printf("%d\n", ans);
	return 0;	
}

#include <bits/stdc++.h>
using namespace std;
int a[1001];
int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", a+i);
	
	dp[1] = 1;
	for(int i = 1; i <= n; i++) {
		if(dp[i] == 0) continue;
		for(int j = 1; (j <= a[i]) && (i+j <= n); j++) {
			if(!dp[i+j] || (dp[i]+1 < dp[i+j])) dp[i+j] = dp[i]+1;
		}
	}	
	printf("%d\n", dp[n]-1);
	
	return 0;	
}

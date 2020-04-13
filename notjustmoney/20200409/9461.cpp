// "파도반 수열", https://www.acmicpc.net/problem/9461
// writen in C++
// 2020. 04.09
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
long long dp[101];
int main() {
	int t;
	scanf("%d", &t);
	dp[1]=dp[2]=dp[3]=1;
	dp[4]=dp[5]=2;
	dp[6]=3;
	dp[7]=4;
	dp[8]=5;
	dp[9]=7;
	for(int i=10; i<=100; i++) {
		dp[i]=dp[i-1]+dp[i-5];	
	}
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;	
}

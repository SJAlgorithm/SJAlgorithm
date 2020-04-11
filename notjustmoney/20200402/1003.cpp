#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pllll;
pllll cnt;
pair<int, pllll> dp[50];
int fibo(int n) {
	if(n == 0) { cnt.first++; return 0; }
	if(n == 1) { cnt.second++; return 1; }
	if(dp[n].first != 0) { 
		cnt.first += dp[n].second.first;
		cnt.second += dp[n].second.second;
		return dp[n].first;
	}
	dp[n].first = fibo(n-1) + fibo(n-2);
	dp[n].second.first = dp[n-1].second.first + dp[n-2].second.first;
	dp[n].second.second = dp[n-1].second.second + dp[n-2].second.second;
	return dp[n].first;
}

int main() {
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		dp[0].second.first = 1; dp[0].second.second = 0;
		dp[1].second.first = 0; dp[1].second.second = 1;
		cnt.first = 0; cnt.second = 0;
		fibo(n);
		printf("%lld %lld\n", cnt.first, cnt.second);
	}
	return 0;	
}

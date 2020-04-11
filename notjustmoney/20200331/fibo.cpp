#include <bits/stdc++.h>
using namespace std;
long long dp[100];
long long fibo(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(dp[n] != 0) return dp[n];
	dp[n] = fibo(n-1)+fibo(n-2);
	return dp[n];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", fibo(n));
	return 0;	
}

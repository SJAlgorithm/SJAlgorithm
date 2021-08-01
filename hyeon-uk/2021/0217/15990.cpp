#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long dp[100001][4];
long long mod = 1000000009;
void solve() {
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
	}
}

int main() {
	solve();
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3])%mod << "\n";
	}
}
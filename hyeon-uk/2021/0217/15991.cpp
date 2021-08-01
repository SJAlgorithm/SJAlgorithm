#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000009
using namespace std;

long long dp[100001][4] = { 0 };

void settings() {
	dp[0][1] = 1;
	dp[1][1] = 1;

	dp[2][1] = 1;
	dp[2][2] = 1;

	dp[3][1] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) % MOD;
		if (i - 4 >= 0)
			dp[i][2] = (dp[i - 4][1] + dp[i - 4][2] + dp[i - 4][3]) % MOD;
		if (i - 6 >= 0)
			dp[i][3] = (dp[i - 6][1] + dp[i - 6][2] + dp[i - 6][3]) % MOD;
	}
}

int main() {
	int n,t;
	settings();
	cin >> t;
	for (int T = 0; T < t; T++) {
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD<<"\n";
	}
}
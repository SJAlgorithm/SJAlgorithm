#include<iostream>
#include<algorithm>

using namespace std;

int day[1001];
int money[1001];
int dp[25000] = { 0 };
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> money[i];
	}
	for (int i = n; i >= 1; i--) {
		if (i + day[i] - 1 > n) {
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(dp[i + day[i]] + money[i], dp[i + 1]);
	}
	cout << dp[1];
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> v;
	int dp[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		int time, score;
		cin >> time >> score;
		v.push_back({ time,score });
	}
	for (int i = 0; i < n;i++) {
		for (int j = t; j >= v[i].first;j--) {
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	cout << dp[t];
}
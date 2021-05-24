#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;

int main() {
	int c, n;
	cin >> c >> n;
	vector<pair<int, int>> v;
	int dp[1001] = { 0 };
	for (int i = 1; i <= c; i++) {
		dp[i] = INF;
	}
	for (int i = 0; i < n; i++) {
		int people, cost;
		cin >> cost >> people;
		v.push_back({ people,cost });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= c; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i - v[j].first >= 0) {
				dp[i] = min(dp[i], dp[i - v[j].first] + v[j].second);
			}
			else {
				dp[i] = min(dp[i], v[j].second);
			}
		}
	}
	cout << dp[c];
}
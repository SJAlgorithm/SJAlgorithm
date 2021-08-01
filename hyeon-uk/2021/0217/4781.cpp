#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	float t;
	while (true) {
		v.clear();
		cin >> n >> t;
		if (n == 0 && t == 0.0) break;
		int dp[10001] = { 0 };
		m = (int)(t * 100+0.5);
		for (int i = 0; i < n; i++) {
			int a;
			float b;
			cin >> a >> b;
			v.push_back({ a,(int)(b*100+0.5) });
		}
		sort(v.begin(), v.end(),compare);
		for (int j = 1; j <= m; j++) {
			for (int i = 0; i < n; i++) {
				if (j - v[i].second < 0) break;
				dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);
			}
		}

		cout << dp[m] << "\n";
	}
	return 0;
}

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int com[301][22] = { 0 };
int dp[301][22] = { 0 };
int path[301][22] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int money;
		cin >> money;
		for (int j = 1; j <= m; j++) {
			cin >> com[money][j];
		}
	}

	for (int company = 1; company <= m; company++) {
		for (int money = 1; money <= n; money++) {
			for (int j = 0; j <= money; j++) {
				int benefit = dp[money - j][company-1] + com[j][company];
				if (benefit > dp[money][company]) {
					dp[money][company] = benefit;
					path[money][company] = j;
				}
			}
		}
	}
	cout << dp[n][m]<<"\n";

	vector<int> res;
	int current = m;
	int cost = n;
	while (current > 0) {
		int now_cost = path[cost][current];
		res.push_back(now_cost);

		cost -= now_cost;
		current--;
	}
	reverse(res.begin(), res.end());
	for (int data : res) {
		cout << data << " ";
	}
}

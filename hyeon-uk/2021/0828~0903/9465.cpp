#include<iostream>
#include<algorithm>
using namespace std;

int maze[100001][2];
int dp[100001][3] = { 0 };
int t, n;

void input() {
	cin >> n;

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) {
			cin >> maze[i][j];
		}
	}
}

int DP() {

	dp[0][0] = maze[0][0];
	dp[0][1] = maze[0][1];

	for (int i = 1; i < n; i++) {
		//1번째꺼 선택 = i-1에서 2번째꺼선택+1번째꺼 / i-1에서 아무것도 선택x+1번째꺼중 큰거
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + maze[i][0];

		//2번째꺼 선택 = i-1에서 1번째꺼선택+i번째에서 2번째꺼 / i-1에서 아무것도 선택x + 2번째꺼 중 큰거
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + maze[i][1];

		//아무것도 선택 x = i-1에서 가장 큰거
		dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
	}
	return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

void solve() {
	input();
	cout<< DP()<<"\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
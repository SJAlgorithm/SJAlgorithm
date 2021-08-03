#include <iostream>
#include<algorithm>
#include<cstring> //memset
#define MAX 987654321	
using namespace std;

int dp[101][101] = { 0 };
bool close[101] = { 0 };
int price[3][3] = { {1,0,10000},{3,1,25000},{5,2,37000} };
int n, m;

int dfs(int day, int cp) {
	if (day <= n) {
		if (dp[day][cp] != MAX) {
			return dp[day][cp];
		}
		if (close[day]) {
			return dp[day][cp] = dfs(day + 1, cp);
		}
		for (int i = 0; i < 3; i++) {
			dp[day][cp] = min(dp[day][cp], dfs(day + price[i][0], cp + price[i][1])+price[i][2]);
		}
		if (3 <= cp) {
			dp[day][cp] = min(dp[day][cp], dfs(day + 1, cp - 3));
		}
		return dp[day][cp];
	}
	else {
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> n >> m;

	memset(dp, MAX, sizeof(dp));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		int day;
		cin >> day;
		close[day] = true;
	}
	cout<<dfs(1, 0);

	return 0;
}
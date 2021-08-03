#include <iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[1500501];
int dp[1500501] = { 0 };
int n, t, p;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int result = 0;
	for (int i = 1; i <= n+1;i++) {
		t = arr[i].first;
		p = arr[i].second;
		result = max(result, dp[i]);

		if (i + t -1> n) continue;

		dp[i + t] = max(dp[i + t], result + p);
	}
	cout << result;
	return 0;
}
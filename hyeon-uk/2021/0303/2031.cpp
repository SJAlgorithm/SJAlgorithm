#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int t, n, d, k;
int arr[1000002];
int dp1[1000002];
int dp2[1000002][11];
int maxValue = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> n >> d >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		dp1[i] = i - (lower_bound(arr + 1, arr + n + 1, arr[i] - d + 1) - arr) + 1;
	}

	for (int kk = 1; kk <= k; kk++) {
		for (int i = 1; i <= n; i++) {
			dp2[i][kk] = max(dp2[i - 1][kk], dp1[i]+dp2[i - dp1[i]][kk - 1]);
		}
	}

	for (int i = 0; i <= n; i++) {
		maxValue = max(maxValue, dp2[i][k]);
	}
	cout << maxValue;
}

#include <iostream>
#include<algorithm>
using namespace std;

int arr[1001][1001];
int dp[1001][1001] = { 0 };
int mv[3][2] = { {-1,-1},{-1,0},{0,-1} };
int n, m;

bool isIn(int i, int j) {
	return i >= 0 && i < n&&j >= 0 && j < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				int bi = i + mv[k][0];
				int bj = j + mv[k][1];

				if (isIn(bi, bj)) {
					dp[i][j] = max(dp[i][j], arr[i][j] + dp[bi][bj]);
				}
			}
		}
	}
	cout << dp[n-1][m-1];
}
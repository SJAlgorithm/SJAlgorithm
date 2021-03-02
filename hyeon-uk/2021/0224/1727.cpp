#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//dp[n][m]= n명의 남자와 m명의 여자가 매칭됐을때 차이의 최솟값들의 합
int dp[1001][1001];
int M[1001];
int W[1001];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> M[i];
	for (int i = 1; i <= m; i++) cin >> W[i];

	sort(M+1, M + n+1);
	sort(W+1, W + m+1);
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			
			if (i == j) dp[i][j] = dp[i - 1][j - 1] + abs(M[i] - W[i]);
			else if (i < j) {
				//여자가 더 많을때
				//min(j에 해당하는 여자가 선택되지 않은경우(dp[i][j-1]) , j에 해당하는 여자가 남자 i와 매칭된경우)
				dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+abs(M[i]-W[j]));
			}
			else {
				dp[i][j] = min(dp[i-1][j], dp[i - 1][j-1] + abs(M[i] - W[j]));
			}
		}
	}
	cout << dp[n][m];
}

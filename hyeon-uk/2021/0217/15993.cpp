#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000009
using namespace std;


//dp[n][m][k]= n을 1,2,3으로 나타내는 수 중 (m==0 짝수 m==1 홀수)개로 이루어진 마지막자리가 k인 경우의 수
long long dp[100001][2][4] = { 0 };

void settings() {
	dp[1][1][1] = 1;
	dp[2][0][1] = 1;
	dp[2][1][2] = 1;
	dp[3][1][1] = 1;
	dp[3][0][1] = 1;
	dp[3][0][2] = 1;
	dp[3][1][3] = 1;


	for (int i = 4; i <= 100000; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[i][0][j] = (dp[i-j][1][1]+dp[i-j][1][2]+dp[i-j][1][3]) % MOD;
			dp[i][1][j] = (dp[i-j][0][1]+dp[i-j][0][2]+dp[i-j][0][3]) % MOD;
		}
	}
}

int main() {
	int n,t,m;
	settings();
	cin >> t;
	for (int T = 0; T < t; T++) {
		cin >> n;
		cout << (dp[n][1][1] + dp[n][1][2] + dp[n][1][3]) % MOD<<" "<<(dp[n][0][1] + dp[n][0][2] + dp[n][0][3])%MOD<<"\n";
	}
}
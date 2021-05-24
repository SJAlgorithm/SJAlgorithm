#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000009
using namespace std;


//dp[n][m][k]= m 개의 1,2,3으로 이루어진 n, 마지막자리k
long long dp[1001][1001][4] = { 0 };

void settings() {
	dp[0][0][1] = 1;
	dp[1][1][1] = 1;
	dp[2][1][2] = 1;
	dp[2][2][1] = 1;
	dp[3][1][3] = 1;
	dp[3][2][1] = 1;
	dp[3][2][2] = 1;
	dp[3][3][3] = 1;

	//ex 4개로 이루어진 4= 1+1+1+1 ==> 이건 곧 3개로 이루어진 3의 총 개수(dp[3][3][1]+dp[3][3][2]+dp[3][3][3])
	//m개로 이루어진 n을 만드려면 dp[n-1][m-1][1]+dp[n-2][m-1][2]+dp[n-3][m-1][3]
	for (int i = 4; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			if(i-1>=0)
			dp[i][j][1] = (dp[i-1][j-1][1]+ dp[i - 1][j - 1][2]+ dp[i - 1][j - 1][3])%MOD;
			if(i-2>=0)
			dp[i][j][2] = (dp[i-2][j-1][1]+ dp[i - 2][j - 1][2]+ dp[i - 2][j - 1][3])%MOD;
			if(i-3>=0)
			dp[i][j][3] = (dp[i-3][j-1][1]+ dp[i - 3][j - 1][2]+ dp[i - 3][j - 1][3])%MOD;
		}
	}
}

int main() {
	int n,t,m;
	settings();
	cin >> t;
	for (int T = 0; T < t; T++) {
		cin >> n>>m;
		cout << (dp[n][m][1] + dp[n][m][2] + dp[n][m][3]) % MOD<<"\n";
	}
}
// <외판원 순회> - BOJ_2098
// 비트마스킹, DP(바텀 업), 그래프이론

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n;
int mat[16][16]{};
int dp[15][1 << 15]{};

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
	int min = 2100000000, temp, mt;

	for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
			cin>>mat[i][j];
			if(!mat[i][j]) mat[i][j] = INF;
		}
    }

	n--;
	for (int i = 0; i < n; i++) dp[i][1 << i] = mat[n][i];
    
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
					if (mask & (1 << j)) continue;
					mt = mask | (1 << j);
					temp = dp[i][mask] + mat[i][j];
					dp[j][mt] = (temp < dp[j][mt]) || !dp[j][mt] ? temp : dp[j][mt];
				}
            }
		}
	}

	for (int i = 0; i < n; i++) {
		temp = dp[i][(1 << n) - 1] + mat[i][n];
		min = min < temp ? min : temp;
	}

	cout<<min;
}
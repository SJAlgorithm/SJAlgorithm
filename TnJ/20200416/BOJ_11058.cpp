// <크리보드> - BOJ_11058
// DP

#include<bits/stdc++.h>
using namespace std;

int N;
long long dp[110]={0,1,2,3,4,5};
long long buf = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 6; i <= N; i++) {
		dp[i] = max({ dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4 });
	}
    cout<<dp[N];
}
// 1391569403904
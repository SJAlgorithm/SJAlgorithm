#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define MOD 123456789
using namespace std;

int n;
bool isPrime[40001] = { 0 };
long long dp[40001] = { 0 };
vector<int> prime;

void SOE() {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}


void input() {
	cin >> n;
}

void solution() {
	dp[0] = 1;
	for (int i = 0; i < prime.size(); i++) {
		int now = prime[i];

		for (int j = now; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - now]) % MOD;
		}
	}
	cout << dp[n];
}

void solve() {
	input();
	SOE();
	solution();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
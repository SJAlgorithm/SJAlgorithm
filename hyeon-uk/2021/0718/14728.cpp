#include <iostream>
#include<vector>
#include<algorithm>
#define TMAX 10001
using namespace std;

typedef pair<int, int> pii;
int N,T;
int dp[TMAX] = { 0 };
vector<pii> score;

void input() {
	cin >> N>>T;
	for (int i = 0; i < N; i++) {
		int K, S;
		cin >> K >> S;
		score.push_back({ K,S });
	}
}


void solution() {
	sort(score.begin(), score.end());
	for (int i = 0; i < score.size(); i++) {
		int k = score[i].first;
		int s = score[i].second;

		for (int i = T; i >= k;i--) {
			dp[i] = max(dp[i], dp[i - k] + s);
		}
	}
	cout << dp[T];
}

void solve() {
	input();
	solution();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
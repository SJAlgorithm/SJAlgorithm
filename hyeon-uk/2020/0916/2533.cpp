#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> maze[1000001], dmaze[1000001];
int n;
int dp[1000001][2];
bool visited[1000001] = { 0 };

void dfs(int now) {
	visited[now] = true;
	for (int next : maze[now]) {
		if (!visited[next]) {
			dmaze[now].push_back(next);
			dfs(next);
		}
	}
}

int getResult(int now, bool adapter) {
	
	if (dp[now][adapter] != -1) {
		return dp[now][adapter];
	}

	if (adapter) {
		dp[now][adapter] = 1;
		for (int next : dmaze[now]) {
			dp[now][adapter] += min(getResult(next, true), getResult(next, false));
		}
	}
	else {
		dp[now][adapter] = 0;
		for (int next : dmaze[now]) {
			dp[now][adapter] += getResult(next, true);
		}
	}
	return dp[now][adapter];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		maze[u].push_back(v);
		maze[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1);

	cout << min(getResult(1, true), getResult(1, false));


	return 0;
}

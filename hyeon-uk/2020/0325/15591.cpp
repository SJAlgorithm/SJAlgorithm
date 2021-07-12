#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

vector<pair<int,int>> maze[5000];
int n, q, k, v;

int dfs(int now, int parent, int usado,int k) {
	int result = 0;
	if (parent!=-1&&usado >= k) {
		result++;
	}

	for (auto i : maze[now]) {
		int next = i.first;
		int next_cost = i.second;
		if (next != parent) {
			result += dfs(next, now, min(usado, next_cost), k);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		maze[a].push_back({ b,c });
		maze[b].push_back({ a,c });
	}

	for (int i = 0; i < q; i++) {
		cin >> k >> v;
		cout << dfs(v, -1, INT_MAX, k)<<"\n";
	}
}

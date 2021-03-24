#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int MAX_N = 30001;
int max_height = (int)floor(log2(MAX_N));
int n, m;
vector<vector<int>> v;
int depth[MAX_N];
int ancestor[MAX_N][30];

void dfs(int now, int parent, int d) {
	depth[now] = d;
	ancestor[now][0] = parent;

	for (int i = 1; i <= max_height; i++) {
		int prev = ancestor[now][i - 1];
		ancestor[now][i] = ancestor[prev][i - 1];
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (next != parent) {
			dfs(next, now, d + 1);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = max_height; i >= 0; i--) {
		if (depth[a] <= depth[ancestor[b][i]]) b = ancestor[b][i];
	}
	if (a == b) return a;
	for (int i = max_height; i >= 0; i--) {
		if (ancestor[a][i] != ancestor[b][i]) {
			a = ancestor[a][i];
			b = ancestor[b][i];
		}
	}
	return ancestor[a][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0, 0);

	cin >> m;
	int now, prev;
	cin >> prev;
	int answer = 0;
	for (int i = 1; i < m; i++) {
		cin >> now;
		int LCA = lca(now, prev);
		//a->b까지 가는 경로의 최단거리= a의 깊이+b의 깊이 - 2*lca의 깊이
		//왜냐하면 a의 깊이+b의 깊이를 해주는 사이에 루트->lca까지 2번 겹치므로 빼주면된다
		answer += depth[now] + depth[prev] - 2 * depth[LCA];
		prev = now;
	}
	cout << answer;
}

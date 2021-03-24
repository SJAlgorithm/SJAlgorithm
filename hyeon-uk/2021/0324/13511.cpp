#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int MAX_N = 100001;
int max_height = (int)floor(log2(MAX_N));
int n, m;
vector<vector<pair<int,int>>> v;
int depth[MAX_N];
int ancestor[MAX_N][20];
long long dist[MAX_N];

void dfs(int now, int parent, int d,long long distance) {
	depth[now] = d;
	ancestor[now][0] = parent;
	dist[now] = distance;

	for (int i = 1; i <= max_height; i++) {
		int prev = ancestor[now][i - 1];
		ancestor[now][i] = ancestor[prev][i - 1];
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int cost = v[now][i].second;
		if (next != parent) {
			dfs(next, now, d + 1,distance+cost);
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

int getK(int a, int b, int k) {
	int LCA = lca(a, b);
	int adepth = depth[a] - depth[LCA];
	int bdepth = depth[b] - depth[LCA];
	//x~lca사이
	if (k <= adepth +1) {
		int diff = k-1;
		for (int i = 19; i >= 0; i--) {
			if (diff >= (1 << i)) {
				diff -= (1 << i);
				a = ancestor[a][i];
			}
		}
		return a;
	}
	else {
		int diff = bdepth - (k - (adepth +1));
		for (int i = 19; i >= 0; i--) {
			if (diff >= (1 << i)) {
				diff -= (1 << i);
				b = ancestor[b][i];
			}
		}
		return b;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b,c;
		cin >> a >> b>>c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0, 0,0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int op,a,b,c;
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
			int LCA = lca(a, b);
			cout << dist[a] + dist[b] - 2 * dist[LCA]<<"\n";
		}
		else {
			cin >> a >> b >> c;
			cout << getK(a, b, c) << "\n";
		}
	}
}

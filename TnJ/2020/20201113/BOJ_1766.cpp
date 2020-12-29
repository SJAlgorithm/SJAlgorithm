// <문제집> - BOJ_1766
// 위상정렬, 우선순위 큐

#include<bits/stdc++.h>
using namespace std;

int N, M;
int dg[32010]{};
vector<int> adj[32010]{};
vector<int> ans;

void topology(int n) {
	priority_queue<int> pq;
	for (int i = 1; i <=n; i++) {
		if (dg[i] == 0) pq.push(-i);
	}
	for (int i = 1; i <= n; i++) {
		int cp = -pq.top();
		pq.pop();
		cout<<cp<<' ';

		for (int i = 0; i < adj[cp].size(); i++) {
			int np = adj[cp][i];
			if (--dg[np] == 0) pq.push(-np);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int a, b;

	while(M--) {
		cin >> a >> b;
		adj[a].push_back(b);
		dg[b]++;
	}

	topology(N);
}
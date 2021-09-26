#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX	10001
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int tc, n, d, c;
vector<pii> maze[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		maze[i].clear();
	}
}

void make_graph() {
	for (int i = 0; i < d; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		maze[v].push_back({ u,w });
	}
}

pii dijk() {
	vector<int> dist(n + 2,INF);
	priority_queue<pii> q;
	pii ret = { 0,0 };
	dist[c] = 0;
	q.push({ 0,c });
	while (!q.empty()) {
		int now = q.top().second;
		int now_dist = -q.top().first;
		q.pop();
		if (now_dist > dist[now]) continue;

		for (pii next : maze[now]) {
			int next_node = next.first;
			int next_cost = next.second+now_dist;
			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				q.push({ -next_cost,next_node });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			ret.first++;
			ret.second = max(ret.second, dist[i]);
		}
	}
	return ret;
}

int main() {
	cin >> tc;
	while (tc--) {
		init();
		cin >> n >> d >> c;
		make_graph();
		pii ret = dijk();
		cout << ret.first<<" "<<ret.second << "\n";
	}

	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define INF 987654321
using namespace std;

vector<pair<int,int>> v[1001];
int dist[1001];
int parent[1001];

int n, m,st,en;
void bfs() {
	priority_queue<pair<int,int>> q;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		if (i == st) {
			dist[i] = 0;
		}
		else {
			dist[i] = INF;
		}
	}

	q.push({ 0,st });

	while (!q.empty()) {
		int cost = -q.top().first;
		int now = q.top().second;
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second;
			
			if (dist[next] > cost + nextcost) {
				parent[next] = now;
				dist[next] = cost + nextcost;
				q.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> st >> en;
	bfs();
	stack<int> answer;
	answer.push(en);
	int p = parent[en];
	while (p != st) {
		answer.push(p);
		p = parent[p];
	}
	answer.push(st);
	cout << dist[en]<<"\n";
	cout << answer.size() << "\n";
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}
	return 0;
}

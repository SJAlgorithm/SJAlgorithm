#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;

int t, n, d, c;


void dijkstra(int n, int d, int c) {
	vector<int> dist(n + 1,INF);
	vector<vector<pair<int,int>>> v(n + 1);
	vector<bool> visited(n + 1, false);
	for (int i = 0; i < d; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		v[to].push_back({ from,cost });
	}

	dist[c] = 0;
	
	while (true) {
		int Mini = 0, MinValue = INF+1;

		for (int i = 1; i <= n; i++) {
			if (!visited[i] && MinValue > dist[i]) {
				MinValue = dist[i];
				Mini = i;
			}
		}

		if (Mini == 0) break;
		visited[Mini] = true;

		for (int i = 0; i < v[Mini].size(); i++) {
			int next = v[Mini][i].first;
			int nextCost = v[Mini][i].second;

			if (dist[next] > dist[Mini] + nextCost) {
				dist[next] = dist[Mini] + nextCost;
			}
		}
	}

	int cnt = 0, Max = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;
			Max = max(Max, dist[i]);
		}
	}
	cout << cnt << " " << Max << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> n >> d >> c;
		dijkstra(n, d, c);
	}

}

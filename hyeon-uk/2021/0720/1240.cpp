#include<iostream>
#include <algorithm>
#include<vector>
#include<queue>
#include<utility>
#define MAX 987654321
using namespace std;

int N, M;
vector<pair<int, long long>> v[1001];
long long dist[1001];

void bfs(int a,int b) {
	priority_queue<pair<long long,int>> pq;//dist,to 페어로 우선순위 큐 저장
	pq.push(make_pair(0, a));

	for (int i = 1; i <= N; i++) dist[i] = MAX;
	dist[a] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		long long dpdist = -1*pq.top().first;
		pq.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nowdist = v[now][i].second;

			if (nowdist + dpdist < dist[next]) {
				dist[next] = nowdist + dpdist;
				pq.push(make_pair(-1*dist[next],next));
			}
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back(make_pair(y, w));
		v[y].push_back(make_pair(x, w));
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		bfs(a, b);
		cout << dist[b]<<"\n";
	}
	return 0;
}
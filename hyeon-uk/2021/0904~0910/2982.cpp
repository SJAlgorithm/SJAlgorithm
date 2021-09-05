#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define MAX 987654321
using namespace std;
typedef pair<int,int> pii;
int N,M;
int A, B, K, G;
vector<int> GV;
vector<pii> maze[1001];
int ban[1001];

pii on_road(int time) {
	for (int i = 0; i < G-1;i++) {
		int node = GV[i];
		int next_node = GV[i + 1];
		if (time <= ban[node]) {
			return { node,next_node };
		}
	}
	return { -1,-1 };
}

int dijk() {
	priority_queue<pii> pq;
	pq.push({ -K,A });
	int dist[1001];
	for (int i = 1; i <= N; i++) dist[i] = MAX;
	while (!pq.empty()) {
		int now = pq.top().second;
		int now_dist = -pq.top().first;
		pq.pop();

		pii king_road = on_road(now_dist);
		
		if (dist[now]<now_dist) continue;
		if (now == B) {
			return dist[now]-K;
		}
		
		for (auto next : maze[now]) {
			int next_node = next.first;
			int w = 0;
			if (king_road == make_pair(now, next_node)||king_road==make_pair(next_node,now)) {
				w = ban[king_road.first] - now_dist;
			}
			int cost = next.second+now_dist+w;

			if (cost< dist[next_node]) {
				pq.push({ -cost,next_node });
				dist[next_node] = cost;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> A >> B >> K >> G;
	GV.resize(G);
	for (int i = 0; i < G; i++) {
		cin >> GV[i];
	}

	for (int i = 0; i < M; i++) {
		int U, V, L;
		cin >> U >> V >> L;
		maze[U].push_back({ V,L });
		maze[V].push_back({ U,L });
	}
	int sum = 0;
	for (int i = 0; i < G - 1; i++) {
		int u = GV[i];
		int v = GV[i + 1];
		int time;
		for (auto next : maze[u]) {
			int next_node = next.first;
			int cost = next.second;
			if (next_node == v) {
				time = cost;
				break;
			}
		}
		sum += time;
		ban[u] = sum;
	}

	int ret = dijk();
	
	cout << ret;
	return 0;
}
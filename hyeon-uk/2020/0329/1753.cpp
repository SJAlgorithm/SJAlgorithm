#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#define MAX 11*20000
#define VMAX 20001
#define EMAX 300001
using namespace std;

typedef struct Node {
	int to;
	int weight;
}Node;


int n, m, s;
int dis[VMAX] = { 0 };
vector<Node> node[VMAX];

void short_path() {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int now_node = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < node[now_node].size(); i++) {
			if (dis[now_node] + node[now_node][i].weight < dis[node[now_node][i].to]) {
				dis[node[now_node][i].to] = dis[now_node] + node[now_node][i].weight;
				pq.push({ -1 * (dis[now_node] + node[now_node][i].weight), node[now_node][i].to });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		node[a].push_back(Node{ b,w });
	}
	
	for (int i = 1; i <= n; i++) {
		dis[i] = MAX;
	}
	dis[s] = 0;
	
	short_path();

	for (int i = 1; i <= n; i++) {
		if (dis[i] == MAX) cout << "INF\n";
		else cout << dis[i] << "\n";
	}
}
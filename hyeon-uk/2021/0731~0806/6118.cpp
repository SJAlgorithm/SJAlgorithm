#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> maze[20001];
int visited[20001] = { 0 };
int n, m;

void make_graph() {
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		maze[a].push_back(b);
		maze[b].push_back(a);
	}
}
void input() {
	cin >> n >> m;
	make_graph();
}


void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visited[1] = 1;

	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int next : maze[now]) {
			if (!visited[next]) {
				visited[next] = dist + 1;
				q.push({ next,dist + 1 });
			}
		}
	}

	int max = 0;
	int max_cnt = 0;
	int maxNode = -1;

	for (int i = 2; i <= n; i++) {
		if (max < visited[i]) {
			max = visited[i];
			maxNode = i;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (max == visited[i]) max_cnt++;
	}
	cout << maxNode << " " << visited[maxNode] - 1 << " " << max_cnt;
}


void solve() {
	input();
	bfs();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
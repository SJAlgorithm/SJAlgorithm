#include <iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

char maze[50][50];
int parent[251];
bool visited[50][50] = { 0 };
int n, m;
vector<pair<pii, int>> edge;
vector<pii> keys;
int mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
pair<int, int> st;

bool compare(pair<pii, int> a, pair<pii, int> b) {
	return a.second < b.second;
}

bool isIn(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

bool bfs(pii st,pii end,int v1,int v2) {
	queue<pair<pair<int, int>, int>> q;
	memset(visited, false, sizeof(visited));
	q.push({ st,0 });
	visited[st.first][st.second] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;

		q.pop();

		if (x == end.first&&y == end.second) {
			edge.push_back({{v1,v2} ,t});
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];

			if (isIn(nx, ny) && !visited[nx][ny] && maze[nx][ny] != '1') {
				q.push({ {nx,ny},t + 1 });
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'S') {
				st = { i,j };
			}
			if (maze[i][j] == 'K') {
				keys.push_back({ i,j });
			}
		}
	}
}

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	else return find(parent[a]);
}

void union_parent(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int make_mst() {
	int total_weight = 0;
	for (int i = 0; i <= m; i++) {
		parent[i] = i;
	}
	//가중치기준 오름차순 정렬
	sort(edge.begin(), edge.end(), compare);

	for (int i = 0; i < edge.size(); i++) {
		int v1 = edge[i].first.first;
		int v2 = edge[i].first.second;
		int w = edge[i].second;

		int pv1 = find(v1);
		int pv2 = find(v2);
		if (pv1 != pv2) {
			union_parent(v1, v2);
			total_weight += w;
		}
	}
	return total_weight;
}

int solution() {
	//정점->각 key들의 거리
	for (int i = 0; i < keys.size(); i++) {
		int kx = keys[i].first;
		int ky = keys[i].second;
		if (!bfs(st, { kx,ky },0,i+1)) {
			return -1;
		}
	}
	//키들간의 거리
	for (int i = 0; i < keys.size(); i++) {
		for (int j = i + 1; j < keys.size(); j++) {
			int kx1 = keys[i].first;
			int ky1 = keys[i].second;
			int kx2 = keys[j].first;
			int ky2 = keys[j].second;
			bfs({ kx1,ky1 }, { kx2,ky2 }, i + 1, j + 1);
		}
	}
	//mst구하기
	return make_mst();
}

void solve() {
	input();
	cout << solution();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
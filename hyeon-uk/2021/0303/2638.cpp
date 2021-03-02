#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int maze[100][100];
int n, m,total=0;
int mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[100][100] = { 0 };
bool isIn(int i, int j) {
	return (i >= 0 && i < n&&j >= 0 && j < m);
}

bool isTarget(int i, int j) {
	int cnt = 0;
	for (int ii = 0; ii < 4; ii++) {
		int ni = i + mv[ii][0];
		int nj = j + mv[ii][1];

		if (isIn(ni, nj) && maze[ni][nj] == -1) {
			cnt++;
		}
	}
	if (cnt >= 2) return true;
	else return false;
}

void refresh() {
	queue<pair<int, int>> q;
	bool vis[100][100] = { 0 };
	q.push({ 0, 0 });
	maze[0][0] = -1;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int ii = 0; ii < 4; ii++) {
			int ni = i + mv[ii][0];
			int nj = j + mv[ii][1];

			if (isIn(ni, nj) && (maze[ni][nj] == 0||maze[ni][nj]==-1)&& !vis[ni][nj]) {
				maze[ni][nj] = -1;
				vis[ni][nj] = true;
				q.push({ ni,nj });
			}
		}
	}
}

void bfs(vector<pair<int,int>>& temp,int i,int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;
	while (!q.empty()) {
		int nowi = q.front().first;
		int nowj = q.front().second;
		q.pop();

		if (isTarget(nowi, nowj)) {
			temp.push_back({ nowi,nowj });
		}

		for (int ii = 0; ii < 4; ii++) {
			int ni = nowi + mv[ii][0];
			int nj = nowj + mv[ii][1];

			if (isIn(ni, nj) && maze[ni][nj] == 1 && !visited[ni][nj]) {
				visited[ni][nj] = true;
				q.push({ ni,nj });
			}
		}
	}
}

void solve() {
	int day = 0;

	while (total > 0) {
		refresh();
		vector<pair<int, int>> clearv;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 1&&!visited[i][j]) {
					bfs(clearv,i,j);
				}
			}
		}
		for (int k = 0; k < clearv.size(); k++) {
			maze[clearv[k].first][clearv[k].second] = -1;
		}
		total -= clearv.size();
		day++;
	}
	cout << day;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 1) total++;
		}
	}
	solve();
}
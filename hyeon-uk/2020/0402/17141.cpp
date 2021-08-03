#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int maze[50][50];
int mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m,result=987654321;
int zero_cnt = 0;
vector<pair<int, int>> virus;
vector<pair<int, int>> se;

bool isIn(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n;
}

void bfs() {
	int time[50][50];
	int cnt = zero_cnt+(virus.size()-m);
	int temp = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			time[i][j] = -1;
		}
	}

	for (int i = 0; i < m; i++) {
		int x = se[i].first;
		int y = se[i].second;
		time[x][y] = 0;
		q.push({ x,y });
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];

			if (isIn(nx, ny) && time[nx][ny] == -1 && maze[nx][ny] != 1) {
				time[nx][ny] = time[x][y] + 1;
				cnt--;
				temp = time[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
	if (!cnt) {
		result = min(result, temp);
	}
}

void dfs(int ind) {
	if (se.size() == m) {
		bfs();
		return;
	}

	for (int i = ind + 1; i < virus.size(); i++) {
		se.push_back(virus[i]);
		dfs(i);
		se.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (maze[i][j] == 0) zero_cnt++;
		}
	}
	dfs(-1);
	if (result == 987654321) {
		result = -1;
	}
	cout << result << "\n";
	return 0;
}

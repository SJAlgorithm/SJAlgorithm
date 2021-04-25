#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int maze[8][8];
int mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
vector<pair<int, int>> zero,virus;
int max_size = -1;

bool isIn(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < m;
}

void bfs() {
	queue<pair<int, int>> q;
	int copy_maze[8][8];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy_maze[i][j] = maze[i][j];
		}
	}

	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first,virus[i].second });
	}

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nowx + mv[i][0];
			int ny = nowy + mv[i][1];

			if (isIn(nx, ny) && copy_maze[nx][ny] == 0) {
				copy_maze[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_maze[i][j] == 0) cnt++;
		}
	}
	max_size = max(max_size, cnt);
	return;
}

void backtracking(int ind, int count) {
	if (count == 3) {
		bfs();
		return;
	}
	for (int i = ind + 1; i < zero.size(); i++) {
		int x, y;
		x = zero[i].first;
		y = zero[i].second;
		maze[x][y] = 1;
		backtracking(i, count + 1);
		maze[x][y] = 0;
	}
	return;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 0) {
				zero.push_back({ i,j });
			}
			else if (maze[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < zero.size() - 2; i++) {
		int x, y;
		x = zero[i].first;
		y = zero[i].second;
		maze[x][y] = 1;
		backtracking(i, 1);
		maze[x][y] = 0;
	}
	cout << max_size << "\n";
}

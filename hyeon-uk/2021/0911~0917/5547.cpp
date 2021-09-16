#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

int maze[101][101] = { 0 };
int mv[2][6][2] = { 
	{ {-1,-1},{0,-1},{1,0},{0,1},{-1,1},{-1,0} },
	{ {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,0} } 
};
int w, h;

bool isIn(int x, int y) {
	return 1 <= x && x <= w && 1 <= y && y <= h;
}

void make_outside() {
	bool visited[101][101] = { 0 };
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (maze[j][i] == 0 && !visited[j][i]) {
				queue<pii> q;
				vector<pii> v;
				q.push({ j,i });
				visited[j][i] = true;
				bool flag = false;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					v.push_back({ x,y });

					for (int d = 0; d < 6; d++) {
						int line = y % 2;
						int nx = x + mv[line][d][0];
						int ny = y + mv[line][d][1];
						if (!isIn(nx, ny)) {
							flag = true;
						}
						else {
							if (maze[nx][ny] == 0 && !visited[nx][ny]) {
								q.push({ nx,ny });
								visited[nx][ny] = true;
							}
						}
					}
				}
				if (flag) {
					for (pii out : v) {
						int x = out.first;
						int y = out.second;
						maze[x][y] = -1;
					}
				}
			}
		}
	}
}

int bfs() {
	int answer = 0;
	bool visited[101][101] = { 0 };

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (maze[j][i] == 1&&!visited[j][i]) {
				queue<pii> q;
				q.push({ j,i });
				visited[j][i] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int d = 0; d < 6; d++) {
						int line = y % 2;
						int nx = x + mv[line][d][0];
						int ny = y + mv[line][d][1];
						if (!isIn(nx, ny)) {
							answer++;
						}
						else {
							if (maze[nx][ny] == 1&& !visited[j][i]) {
								q.push({ nx,ny });
								visited[nx][ny] = true;
							}
							else if (maze[nx][ny] == -1) {
								answer++;
							}
						}
					}
				}
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> w >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> maze[j][i];
		}
	}
	make_outside();

	cout << bfs() << "\n";
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
char maze[12][6];
int mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[12][6];

void input() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> maze[i][j];
		}
	}
}
void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = false;
		}
	}
}

bool compare(pii a, pii b) {
	return a.first < b.first;
}

bool isIn(int x, int y) {
	return 0 <= x && x < 12 && 0 <= y && y < 6;
}

vector<pii> bfs(int i, int j) {
	char c = maze[i][j];
	vector<pii> result;
	queue<pii> q;
	q.push({ i,j });
	result.push_back({ i,j });
	visited[i][j] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + mv[d][0];
			int ny = y + mv[d][1];

			if (isIn(nx, ny) && !visited[nx][ny] && maze[nx][ny] == c) {
				q.push({ nx,ny });
				result.push_back({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	return result;
}

void popAndDonwPuzzle(vector<pii>& puzzle) {
	sort(puzzle.begin(), puzzle.end(), compare);
	for (pii pz : puzzle) {
		int x = pz.first;
		int y = pz.second;

		if (x == 0) maze[x][y] = '.';
		else {
			for (int i = x; i >= 1; i--) {
				maze[i][y] = maze[i - 1][y];
				maze[i - 1][y] = '.';
			}
		}
	}
}

void solve() {
	int cnt = 0;
	while (true) {
		bool change = false;
		init();
		vector<pii> puzzles;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (maze[i][j] != '.'&&!visited[i][j]) {
					vector<pii> puzzle = bfs(i, j);
					if (puzzle.size() >= 4) {
						puzzles.insert(puzzles.end(),puzzle.begin(),puzzle.end());
						change = true;
					}
				}
			}
		}
		if (!change) break;
		popAndDonwPuzzle(puzzles);
		cnt++;
	}
	cout << cnt << "\n";
}

int main() {
	input();
	solve();
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int maze[10][10];
bool flower[10][10] = { 0 };
int mv[5][2] = { {0,0},{1,0},{-1,0},{0,1},{0,-1} };
int n, ret = 987654321;

bool isIn(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool flower_check(int x, int y) {
	for (int k = 0; k < 5; k++) {
		int nx = x + mv[k][0];
		int ny = y + mv[k][1];
		if (!isIn(nx, ny) || flower[nx][ny]) {
			return false;
		}
	}
	return true;
}

int blossom(int x, int y) {
	int s = 0;
	for (int k = 0; k < 5; k++) {
		int nx = x + mv[k][0];
		int ny = y + mv[k][1];
		flower[nx][ny] = true;
		s += maze[nx][ny];
	}
	return s;
}

void falling(int x, int y) {
	for (int k = 0; k < 5; k++) {
		int nx = x + mv[k][0];
		int ny = y + mv[k][1];
		flower[nx][ny] = false;
	}
}

void dfs(int x, int y, int sum, int cnt) {
	if (cnt == 3) {
		ret = min(ret, sum);
		return;
	}
	for (int i = x; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (flower_check(i, j)) {
				int s = blossom(i, j);
				dfs(i, j, sum + s, cnt + 1);
				falling(i, j);
			}
		}
	}
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}
}

void solve() {
	input();
	dfs(0, 0, 0, 0);
	cout << ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}
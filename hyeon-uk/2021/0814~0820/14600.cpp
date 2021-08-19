#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int maze[5][5] = { 0 };
int k, x, y;
bool flag1 = false;
int tile[8][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{-1,0},{-1,1}},
	{{0,0},{-1,0},{-1,-1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{0,-1},{1,-1}},
	{{0,0},{0,-1},{-1,-1}},
};

bool isIn(int i, int j) {
	return 1 <= i && i <= k && 1 <= j && j <= k && maze[i][j] == 0;
}

void dfs(int num,int left) {
	if (left == 0) {
		for (int i = k; i >=1; i--) {
			for (int j = 1; j <= k; j++) {
				cout << maze[i][j] << " ";
			}
			cout << "\n";
		}
		flag1 = true;
		return;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (maze[i][j] == 0) {
				for (int k = 0; k < 8; k++) {
					bool flag = true;
					for (int k1 = 0; k1 < 3; k1++) {
						int nx = i + tile[k][k1][0];
						int ny = j + tile[k][k1][1];

						if (!isIn(nx, ny)) {
							flag = false;
							break;
						}
					}
					if (flag) {
						for (int k1 = 0; k1 < 3; k1++) {
							int nx = i + tile[k][k1][0];
							int ny = j + tile[k][k1][1];
							maze[nx][ny] = num;
						}
						dfs(num + 1, left - 3);
						if (flag1) return;
						for (int k1 = 0; k1 < 3; k1++) {
							int nx = i + tile[k][k1][0];
							int ny = j + tile[k][k1][1];
							maze[nx][ny] = 0;
						}
					}
				}
				if (flag1) return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k;
	cin >> y >> x;
	maze[x][y] = -1;
	k = pow(2, k);
	dfs(1, k*k - 1);

	return 0;
}
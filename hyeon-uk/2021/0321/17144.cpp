#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int maze[50][50];
int mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int Rclock[4] = { 3,0,2,1 };
int clock[4] = {2,0,3,1};
int R, C, T;
vector<pair<int, int>> cleaner;

bool isIn(int r, int c) {
	return r >= 0 && r < R&&c >= 0 && c < C;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == -1) {
				cleaner.push_back({ i,j });
			}
		}
	}

	for (int t = 0; t < T; t++) {
		queue<pair<pair<int, int>,int>> dust;
		//먼지저장
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (maze[i][j]>=1) {
					dust.push({ { i,j } ,maze[i][j]});
				}
			}
		}

		//동시확산
		while (!dust.empty()) {
			int r = dust.front().first.first;
			int c = dust.front().first.second;
			int amount = dust.front().second;

			dust.pop();

			for (int i = 0; i < 4; i++) {
				int nextr = r + mv[i][0];
				int nextc = c + mv[i][1];

				if (isIn(nextr, nextc) && maze[nextr][nextc] != -1) {
					maze[nextr][nextc] += amount / 5;
					maze[r][c] -= amount / 5;
				}
			}
		}

		int upr = cleaner[0].first-1;
		int upc = cleaner[0].second;

		//청정기 위쪽 on
		for (int i = 0; i < 4; i++) {
			while (true) {
				int nextr = upr + mv[Rclock[i]][0];
				int nextc = upc + mv[Rclock[i]][1];

				if (!isIn(nextr, nextc)) break;
				if (nextr == cleaner[0].first&&nextc == cleaner[0].second) break;
				if (nextr > cleaner[0].first) break;
				maze[upr][upc] = maze[nextr][nextc];
				upr = nextr;
				upc = nextc;
			}
		}
		maze[upr][upc] = 0;
		
		//청정기 아래쪽 on
		int downr = cleaner[1].first + 1;
		int downc = cleaner[1].second;
		for (int i = 0; i < 4; i++) {
			while (true) {
				int nextr = downr + mv[clock[i]][0];
				int nextc = downc + mv[clock[i]][1];

				if (!isIn(nextr, nextc)) break;
				if (nextr == cleaner[1].first&&nextc == cleaner[1].second) break;
				if (nextr < cleaner[1].first) break;
				maze[downr][downc] = maze[nextr][nextc];
				downr = nextr;
				downc = nextc;
			}
		}
		maze[downr][downc] = 0;
		
	}

	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] >= 1) {
				cnt += maze[i][j];
			}
		}
	}
	cout << cnt << "\n";
}

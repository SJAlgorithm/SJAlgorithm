#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<pair<pair<pair<int, int>, int>, int>, int> shark;
vector<shark> maze[101][101];
int r, c, m,result=0;
int mv[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool isIn(int x, int y) {
	return x >= 1 && x <= r && y >= 1 && y <= c;
}

int change_d(int d) {
	if (d == 0) return 1;
	if (d == 1) return 0;
	if (d == 2) return 3;
	if (d == 3) return 2;
}

void fishing(int i) {
	for (int j = 1; j <= r; j++) {
		if (!maze[j][i].empty()) {
			result += maze[j][i].front().second;
			maze[j][i].pop_back();
			return;
		}
	}
}

void moving() {
	vector<shark> newSharks[102][102];

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (maze[i][j].empty()) continue;

			int x = i;
			int y = j;
			int sp = maze[i][j][0].first.first.second;
			int temp = sp;
			int d = maze[i][j][0].first.second;
			int sz = maze[i][j][0].second;
			maze[i][j].pop_back();
			while (temp--) {
				int nx = x + mv[d][0];
				int ny = y + mv[d][1];
				if (!isIn(nx, ny)) {
					d = change_d(d);
				}
				x += mv[d][0];
				y += mv[d][1];
			}

			if (newSharks[x][y].empty()) {
				newSharks[x][y].push_back({ {{{x,y} ,sp },d }, sz });
			}
			else {
				if (newSharks[x][y][0].second < sz) {
					newSharks[x][y].pop_back();
					newSharks[x][y].push_back({ {{{x,y} ,sp },d }, sz });
				}
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			maze[i][j] = newSharks[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		d--;
		if (d == 0 || d == 1) {
			s = s%((r-1)*2);
		}
		else {
			s = s % ((c - 1) * 2);
		}
		maze[x][y].push_back( {{{{x,y},s},d},z});
	}
	for (int i = 1; i <= c; i++) {
		fishing(i);
		moving();
	}
	cout << result << "\n";
	return 0;
}

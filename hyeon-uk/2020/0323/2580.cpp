#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool row[9][10], col[9][10], box[9][10];
int maze[9][9];
bool flag = false;
vector<pair<int,int>> zero;
int getBox(int i, int j) {
	if (i < 3) {
		if (j < 3) {
			return 0;
		}
		else if (j < 6) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (i < 6) {
		if (j < 3) {
			return 3;
		}
		else if (j < 6) {
			return 4;
		}
		else {
			return 5;
		}
	}
	else {
		if (j < 3) {
			return 6;
		}
		else if (j < 6) {
			return 7;
		}
		else {
			return 8;
		}
	}
}

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> maze[i][j];
			if (maze[i][j] != 0) {
				row[i][maze[i][j]] = true;
				col[j][maze[i][j]] = true;
				int b = getBox(i, j);
				box[b][maze[i][j]] = true;
			}
			else {
				zero.push_back({ i,j });
			}
		}
	}
}

void dfs(int ind) {
	if (ind == zero.size()) {
		flag = true;
		return;
	}

	int x = zero[ind].first;
	int y = zero[ind].second;
	int b = getBox(x, y);
	for (int i = 1; i <= 9; i++) {
		if (!row[x][i] && !col[y][i] && !box[b][i]) {
			maze[x][y] = i;
			row[x][i] = col[y][i] = box[b][i] = true;
			dfs(ind + 1);
			if (flag) {
				return;
			}
			maze[x][y] =0;
			row[x][i] = col[y][i] = box[b][i] = false;
		}
	}
}

void solve() {
	dfs(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << maze[i][j]<<" " ;
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	solve();
}

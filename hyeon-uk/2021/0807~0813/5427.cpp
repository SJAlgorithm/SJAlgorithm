#include <iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

char maze[1000][1000];
int mv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
pair<int, int> st;
queue<pair<int, int>> fire;
int n, m;

bool isIn(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void fireMoving() {
	int fsize = fire.size();
	for(int k=0;k<fsize;k++){
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];

			if (isIn(nx, ny) && maze[nx][ny] != '#'&&maze[nx][ny] != '*') {
				maze[nx][ny] = '*';
				fire.push({ nx,ny });
			}
		}
	}
}

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	bool visited[1000][1000] = { 0 };
	q.push({ st,0 });
	visited[st.first][st.second] = true;

	while (!q.empty()) {
		fireMoving();
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			
			for (int j = 0; j < 4; j++) {
				int nx = x + mv[j][0];
				int ny = y + mv[j][1];
				//탈출
				if (!isIn(nx, ny)) {
					cout << cnt+1<<"\n";
					return;
				}

				if (!visited[nx][ny] && maze[nx][ny] == '.') {
					q.push({ { nx,ny },cnt + 1 });
					visited[nx][ny] = true;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return ;
}

void input() {
	cin >> m >> n;
	while (!fire.empty()) fire.pop();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '@') {
				st = { i,j };
			}
			if (maze[i][j] == '*') {
				fire.push({ i,j });
			}
		}
	}
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		input();
		bfs();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
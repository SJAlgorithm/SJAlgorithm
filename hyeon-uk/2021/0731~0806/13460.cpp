#include <iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

char maze[10][10];
bool visited[10][10][10][10] = { 0 };
int mv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
pair<int, int> goal, red, blue;
int n, m;

bool isIn(int i, int j) {
	return (maze[i][j] != '#');
}

bool isGoal(int i, int j) {
	return (maze[i][j] == 'O');
}

pair<int, int> moving(int i, int j, int d) {
	pair<int, int> result = { i,j };

	while (true){
		result.first += mv[d][0];
		result.second += mv[d][1];

		if (!isIn(result.first, result.second)) {
			result.first -= mv[d][0];
			result.second -= mv[d][1];
			break;
		}
		if (isGoal(result.first, result.second)) {
			break;
		}
	}
	return result;
}

int bfs() {
	queue<pair<pair<pair<int, int>, pair<int, int>>,int>>q;

	q.push({ {red,blue} ,0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		int ri = q.front().first.first.first;
		int rj = q.front().first.first.second;
		int bi = q.front().first.second.first;
		int bj = q.front().first.second.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt > 9) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			pair<int, int> rn, bn;
			rn = moving(ri, rj, i);
			bn = moving(bi, bj, i);

			if (rn == goal) {
				if (bn == goal) {
					continue;
				}
				else {
					return cnt + 1;
				}
			}
			else if (bn == goal) {
				continue;
			}

			//움직이고 겹쳤으면, 조정
			if (rn == bn) {
				//밑으로 내려가는 방향이였을때 겹치면, 더 위에있던공의 i좌표 --
				if (i == 0) {
					if (ri < bi) {
						rn.first--;
					}
					else {
						bn.first--;
					}
				}
				//위로 올라가는 방향이였을때 겹치면, 더 아래있던공의 i좌표 ++;
				else if (i == 1) {
					if (ri < bi) {
						bn.first++;
					}
					else {
						rn.first++;
					}
				}
				//오른쪽으로 가는 방향이였을때 겹치면, 더 왼쪽에있던 공의 j좌표 --;
				else if (i == 2) {
					if (rj < bj) {
						rn.second--;
					}
					else {
						bn.second--;
					}
				}
				//왼쪽으로 가는 방향이였을때 겹치면, 더 오른쪽에 있던 공의 j좌표 ++;
				else {
					if (rj < bj) {
						bn.second++;
					}
					else {
						rn.second++;
					}
				}
			}

			if (!visited[rn.first][rn.second][bn.first][bn.second]) {
				q.push({ {rn,bn},cnt + 1 });
				visited[rn.first][rn.second][bn.first][bn.second] = true;
			}
		}
	}
	return -1;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'O') {
				goal = { i,j };
			}
			if (maze[i][j] == 'B') {
				blue = { i,j };
			}
			if (maze[i][j] == 'R') {
				red = { i,j };
			}
		}
	}
}

void solve() {
	input();
	cout<<bfs();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
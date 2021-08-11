#include <iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 987654321
using namespace std;

int maze[3][3];
int t, result;
bool visited[512];

//열 바꾸는 함수
void col_change(int col) {
	for (int i = 0; i < 3; i++) {
		maze[i][col] = (maze[i][col] == 1 ? 0 : 1);
	}
}

//행 바꾸는 함수
void row_change(int row) {
	for (int i = 0; i < 3; i++) {
		maze[row][i] = (maze[row][i] == 1 ? 0 : 1);
	}
}

//대각선 바꾸는 함수
void cross_change(int dir) {
	for (int i = 0; i < 3; i++) {
		if (dir == 0) {
			maze[i][i] = (maze[i][i] == 1 ? 0 : 1);
		}
		else {
			maze[i][2 - i] = (maze[i][2 - i] == 1 ? 0 : 1);
		}
	}
}

//모든면이 같은지 확인하는 함수
bool isCorrect() {
	char temp = maze[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (temp != maze[i][j]) {
				return false;
			}
		}
	}
	return true;
}

//현재 상태를 정수로 매핑하는 함수
int maze_to_int() {
	int now = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			now = now * 2 + maze[i][j];
		}
	}
	return now;
}

//매핑된 함수를 이용하여 현재 상태를 표현해주는 함수
void int_to_maze(int number) {
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j >= 0; j--) {
			maze[i][j] = number % 2;
			number /= 2;
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	int first = maze_to_int();
	q.push({ first,0 });
	visited[first] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		int_to_maze(now);

		if (isCorrect()) {
			return cnt;
		}

		//열 변환
		for (int i = 0; i < 3; i++) {
			col_change(i);
			int next = maze_to_int();
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next ,cnt + 1 });
			}
			col_change(i);
		}

		//행변환
		for (int i = 0; i < 3; i++) {
			row_change(i);
			int next = maze_to_int();
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next ,cnt + 1 });
			}
			row_change(i);
		}
		//대각선 변환
		for (int i = 0; i <= 1; i++) {
			cross_change(i);
			int next = maze_to_int();
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next ,cnt + 1 });
			}
			cross_change(i);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		result = MAX;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char data;
				cin >> data;
				if (data == 'H') {
					maze[i][j] = 1;
				}
				else {
					maze[i][j] = 0;
				}
			}
		}
		cout << bfs() << "\n";


	}

	return 0;
}
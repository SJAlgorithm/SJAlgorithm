#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

char maze[101][101];
int mv[4][2] = { {-1,0},{0,1},{0,-1},{1,0} };
int r, c, n, line;

bool isIn(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

bool isBottom(int x) {
	return x == r - 1;
}

//미네랄 정렬기준을 더 아래쪽에 있는것부터 정렬
bool compare(pii a, pii b) {
	return a.first > b.first;
}

void down(int a, int b) {
	vector<pii> mineral;
	maze[a][b] = '.';
	//떠있는 미네랄을 찾기위함.
	for (int i = 0; i < 4; i++) {
		int nx = a + mv[i][0];
		int ny = b + mv[i][1];
		if (isIn(nx, ny) && maze[nx][ny] == 'x') {
			bool flag = true;
			bool visited[101][101] = { 0 };
			queue<pii> q;
			q.push({ nx,ny });
			mineral.push_back({ nx,ny });
			visited[nx][ny] = true;
			//미네랄 수집
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (isBottom(x)) {
					flag = false;
					break;
				}
				for (int i = 0; i < 4; i++) {
					int nx = x + mv[i][0];
					int ny = y + mv[i][1];

					if (isIn(nx, ny) && maze[nx][ny] == 'x' && !visited[nx][ny]) {
						q.push({ nx,ny });
						mineral.push_back({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
			if (flag) break;
			else mineral.clear();
		}
	}
	if (mineral.empty()) return; //미네랄이 없으면 return;

	//아래쪽에있는미네랄을 우선순위로 정렬
	sort(mineral.begin(), mineral.end(), compare);

	//미네랄 이동전 복사
	char tempMaze[101][101];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tempMaze[i][j] = maze[i][j];
		}
	}
	//충돌까지 미네랄 이동
	while (true) {
		bool crush = false;
		for (int i = 0; i < mineral.size(); i++) {
			int x = mineral[i].first+1;//한칸 아래로
			int y = mineral[i].second;

			if (isIn(x, y) && tempMaze[x][y] == '.') {
				tempMaze[x][y] = 'x';
				tempMaze[x - 1][y] = '.';
				mineral[i].first += 1;
			}
			else {
				crush = true;
				break;
			}
		}
		if (crush) return;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				maze[i][j] = tempMaze[i][j];
			}
		}
	}
	
}

void hitMineral(bool left,int l) {
	l = r - l;//위아래 바꾸기위해
	if (left) {
		for (int i = 0; i < c; i++) {
			if (maze[l][i] == 'x') {
				down(l, i);
				return;
			}
		}
	}
	else {
		for (int i = c-1; i >=0; i--) {
			if (maze[l][i] == 'x') {
				down(l, i);
				return;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> maze[i][j];
		}
	}

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> line;
		hitMineral(i%2,line);
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << maze[i][j];
		}
		cout << "\n";
	}
	return 0;
}
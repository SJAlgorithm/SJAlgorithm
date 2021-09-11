#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 
typedef struct node {
	int z,x, y;
}node;
 
int maze[100][100][100];
int mv[6][3] = { //위아래, 좌우, 상하로 움직임
	{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},
{1,0,0},{-1,0,0}
};
int m, n, h;
int blank;//익지않은 토마토
queue<node> tomato;
 
void input() {
	cin >> m >> n >> h;
 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> maze[i][j][k];
				if (maze[i][j][k] == 0) blank++;
				if (maze[i][j][k] == 1) tomato.push({ i,j,k });
			}
		}
	}
}
 
bool isIn(int z, int x, int y) {
	return (z >= 0 && z < h&&x >= 0 && x < n&&y >= 0 && y < m);
}
 
int bfs() {
	int time = 0;
	while (!tomato.empty()&&blank) {
        //오늘 익은 토마토들이 같은날 다른 토마토를 익게하지 않기위해
        //어제익은 토마토들만을 기준으로 bfs
		int tsize = tomato.size();
		for (int i = 0; i < tsize; i++) {
			int z = tomato.front().z;
			int x = tomato.front().x;
			int y = tomato.front().y;
			tomato.pop();
 
			for (int d = 0; d < 6; d++) {
				int nz = z + mv[d][0];
				int nx = x + mv[d][1];
				int ny = y + mv[d][2];
 
				if (isIn(nz, nx, ny) && maze[nz][nx][ny] == 0) {
					maze[nz][nx][ny] = 1;
					blank--;
					tomato.push({ nz,nx,ny });
				}
			}
		}
		time++;
	}
	if (blank) {
		return -1;
	}
	else {
		return time;
	}
}
 
int main() {
	input();
	cout << bfs() << "\n";
}

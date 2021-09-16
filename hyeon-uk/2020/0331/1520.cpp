#include<iostream>
#include <algorithm>
#include<memory.h>
using namespace std;

int maze[501][501];
int dp[501][501];
int mv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;

int dfs(int x,int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if (x < 0 || x >= N || y < 0 || y >= M) return 0;
	if (x == 0 && y == 0) return 1;

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + mv[i][0];
		int ny = y + mv[i][1];

		if(maze[x][y] < maze[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout<<dfs(N-1,M-1);
	return 0;
}
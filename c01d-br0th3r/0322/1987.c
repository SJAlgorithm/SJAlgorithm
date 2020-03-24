#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 401

int visited[MAX] = { 0 };
char board[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int R, C;
int result = 1;

int Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void dfs(int y, int x, int cnt) {
	int nextY, nextX;
	int i, j;
	int alpha;

	result = Max(result, cnt);
	alpha = board[y][x] - 'A';
	visited[alpha] = 1;

	for (i = 0; i < 4; i++) {
		nextY = y + dy[i];
		nextX = x + dx[i];

		if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {
			alpha = board[nextY][nextX] - 'A';

			if (!visited[alpha]) {
				dfs(nextY, nextX, cnt + 1);
			}
		}
	}

	--cnt;
	visited[board[y][x] - 'A'] = 0;

}

int main() {
	int i;

	scanf("%d %d", &R, &C);

	for (i = 0; i < R; i++) {
		scanf("%s", board[i]);
		getchar();
	}

	visited[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	printf("%d\n", result);
	
	return 0;
}

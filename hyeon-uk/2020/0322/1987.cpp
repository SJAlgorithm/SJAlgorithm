#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 987654321
using namespace std;

int n,m, mx = -1;
char arr[21][21];
int mv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool visited[27] = { 0 };
void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int x, int y,int cnt) {
	if (cnt > mx) mx = cnt;
	visited[arr[x][y]-'A'] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + mv[i][0];
		int ny = y + mv[i][1];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !visited[arr[nx][ny]-'A']) {
			dfs(nx, ny,cnt+1);
		}
	}
	visited[arr[x][y] - 'A'] = false;
}

void solve() {
	dfs(0, 0,1);
	cout << mx << "\n";
}

int main(){
	cin >> n>>m;
	input();
	solve();
	return 0;
}



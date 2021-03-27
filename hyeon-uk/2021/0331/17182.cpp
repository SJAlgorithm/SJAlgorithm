#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int maze[10][10];
int answer = 987654321;
bool visited[10];
void dfs(int now, int dist,int cnt) {
	if (cnt == n) {
		answer = min(answer, dist);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, dist + maze[now][i], cnt + 1);
			visited[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == k || k == j || j == i) continue;
				if (maze[i][j] > maze[i][k] + maze[k][j]) {
					maze[i][j] = maze[i][k] + maze[k][j];
				}
			}
		}
	}
	visited[m] = true;
	dfs(m, 0, 1);

	cout << answer << "\n";
}

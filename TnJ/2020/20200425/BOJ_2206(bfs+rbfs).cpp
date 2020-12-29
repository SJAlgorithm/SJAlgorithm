// <벽 부수고 이동하기> - BOJ_2206
// BFS: min(bfs + rbfs) 으로 답내는 신박한 풀이...

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
const int INF = 987654321;
char a[1000][1000];
int N, M;
queue<p> q;
int dist[1000][1000];
int rdist[1000][1000];
int dx[] = { 1, -1 ,0 ,0 };
int dy[] = { 0, 0 ,1 ,-1 };

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

void bfs() {
	q.push({ 0,0 });
	dist[0][0] = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (a[r][c] == '1') continue;
		for (int k = 0; k < 4; ++k) {
			int nr = r + dx[k];
			int nc = c + dy[k];
			if (check(nr, nc) && dist[nr][nc] == -1) {
				q.push({ nr,nc });
				dist[nr][nc] = dist[r][c] + 1;
			}
		}
	}
}

void rbfs() {
	q.push({ N-1,M-1 });
	rdist[N-1][M-1] = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (a[r][c] == '1') continue;
		for (int k = 0; k < 4; ++k) {
			int nr = r + dx[k];
			int nc = c + dy[k];
			if (check(nr, nc) && rdist[nr][nc] == -1) {
				q.push({ nr,nc });
				rdist[nr][nc] = rdist[r][c] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(dist, -1, sizeof(dist));
	memset(rdist, -1, sizeof(rdist));
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	bfs();
	rbfs();
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dist[i][j] != -1 && rdist[i][j] != -1)
				ans = min(ans, dist[i][j] + rdist[i][j]);
		}
	}
	if(ans != INF)
		cout << ans+1 << "\n";
	else cout << "-1\n";

	return 0;
}
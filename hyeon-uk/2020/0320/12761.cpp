#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

queue<pair<int,int>> q;
bool visited[100001] = { 0 };
int a, b, n, m;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b >> n >> m;

	q.push({ n,0 });
	visited[n] = true;
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (now == m) {
			cout << cnt;
			break;
		}

		if (now + a<=100000) {
			if (!visited[now + a]) {
				q.push({ now + a ,cnt+1});
				visited[now + a] = true;
			}
		}
		if (now - a >= 0) {
			if (!visited[now - a]) {
				q.push({ now - a,cnt + 1 });
				visited[now - a] = true;
			}
		}
		if (now + b <= 100000) {
			if (!visited[now + b]) {
				q.push({ now + b,cnt + 1 });
				visited[now + b] = true;
			}
		}
		if (now - b >= 0) {
			if (!visited[now - b]) {
				q.push({ now - b,cnt + 1 });
				visited[now - b] = true;
			}
		}
		if (now*a <= 100000) {
			if (!visited[now*a]) {
				visited[now*a] = true;
				q.push({ now*a,cnt + 1 });
			}
		}
		if (now*b <= 100000) {
			if (!visited[now* b]) {
				q.push({ now*b,cnt + 1 });
				visited[now*b] = true;
			}
		}
		if (now + 1 <= 100000) {
			if (!visited[now + 1]) {
				q.push({ now + 1,cnt + 1 });
				visited[now + 1] = true;
			}
		}
		if (now - 1 >= 0) {
			if (!visited[now-1]) {
				q.push({ now - 1,cnt + 1 });
				visited[now - 1] = true;
			}

		}

	}

}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int visited[101] = { 0 };
int arr[101] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= 100; i++) {
		visited[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	queue<int> q;
	q.push(1);
	visited[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (visited[100]!=-1) break;

		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (arr[next] != 0) {
				next = arr[next];
			}
			if (visited[next] == -1 && now + i <= 100) {
				q.push(next);
				visited[next] = visited[now] + 1;
			}
		}
	}
	cout << visited[100] << "\n";

	return 0;
}

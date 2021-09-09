#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	int c = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<int> maze[501];
		bool visited[501] = { 0 };
		int tree = 0;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			maze[u].push_back(v);
			maze[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				queue<pair<int,int>> q;
				q.push({ i,-1 });
				bool cycle = false;
				while (!q.empty()) {
					int now = q.front().first;
					int parent = q.front().second;
					q.pop();

					for (int next : maze[now]) {
						if (next!=parent) {
							if (visited[next]) {
								cycle = true;
								break;
							}
							else {
								q.push({ next,now });
							}
						}
					}
					if (cycle) break;
				}
				if(!cycle) tree++;
			}
		}

		string answer = "";
		if (!tree) {
			answer = "No trees.\n";
		}
		else if (tree == 1) {
			answer = "There is one tree.\n";
		}
		else {
			answer = "A forest of " + to_string(tree) + " trees.\n";
		}
		cout << "Case " << c++ << ": " << answer;
	}

	return 0;
}
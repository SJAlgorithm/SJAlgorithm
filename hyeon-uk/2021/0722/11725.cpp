#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int parent[100001];
vector<int> v[100001];
bool visited[100001] = { 0 };

void dfs(int node) {

	visited[node]=true;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visited[next]) {
			parent[next] = node;
			dfs(next);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a>> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> v;
vector<int> temp;
bool visited[9] = { 0 };

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	int number[10001] = { 0 };
	for (int i = 0; i < temp.size(); i++) {
		if (!visited[i] && number[temp[i]] == 0) {
			visited[i] = true;
			v[depth] = temp[i];
			number[temp[i]] = 1;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(m);
	temp.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp.begin(), temp.end());
	dfs(0);
	return 0;
}
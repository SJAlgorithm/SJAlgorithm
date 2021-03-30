#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;

vector<string> names;
vector<vector<int>> v(1005);//자기하고 연결된 노드들
vector<vector<int>> children(1005);//자기의 자식들을 저장할 벡터
map<string, int> index;
vector<int> root;
queue<int> q;
int indeg[1005] = { 0 };
int n, m;

void input() {
	string str,a,b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		names.push_back(str);
	}
	sort(names.begin(), names.end());
	for (int i = 0; i < n; i++) index[names[i]] = i;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int index_a = index[a];
		int index_b = index[b];
		v[index_b].push_back(index_a);
		indeg[index_a]++;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) {
			root.push_back(i);
			q.push(i);
		}
	}
	
	cout << root.size() << "\n";
	for (int i = 0; i < root.size(); i++) {
		cout << names[root[i]] << " ";
	}
	cout << "\n";

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int k : v[now]) {
			indeg[k]--;
			if (!indeg[k]) {
				children[now].push_back(k);
				q.push(k);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << names[i] << " " << children[i].size() << " ";
		sort(children[i].begin(), children[i].end());
		for (int k : children[i]) {
			cout << names[k] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}

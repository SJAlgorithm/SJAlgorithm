#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#define MAX 100001
using namespace std;

set<int> nodes;
vector<int> tree[MAX];
int indeg[MAX],tc=1;
bool isTree,visited[MAX];

void print_result() {
	cout << "Case " << tc++ << " is " << (isTree ? "a" : "not a") << " tree.\n";
}

void init() {
	for (int node : nodes) tree[node].clear();
	nodes.clear();
	for (int i = 0; i < MAX; i++) {
		indeg[i] = 0;
		visited[i] = false;
	}
	isTree = true;
}

bool make_tree() {
	int u, v;
	cin >> u >> v;
	if (u < 0 && v < 0) {
		return true;
	}

	while (u!=0&&v!=0) {
		tree[u].push_back(v);
		indeg[v]++;
		nodes.insert(u);
		nodes.insert(v);
		
		cin >> u >> v;
	}
	return false;
}

//진입차수가 맞지 않거나, 루트가 없으면 -1리턴, 아니면 루트노드 리턴
int valid_indeg() {
	int zero_cnt = 0;
	int root = -1;
	for (int node : nodes) {
		if (indeg[node] == 0) {
			zero_cnt++;
			root = node;
		}
		else if (indeg[node] > 1) return -1;
	}
	return zero_cnt == 1 ? root : -1;
}

void trace(int root,int node) {
	for (int next : tree[node]) {
		if (visited[next] || next == root) {
			isTree = false;
			return;
		}
		visited[next] = true;
		trace(root, next);
	}
}

void all_visited(int root) {
	for (int node : nodes) {
		if (node == root) continue;
		if (!visited[node]) {
			isTree = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		init();
		bool isEnd = make_tree();
		if (isEnd) break;
		if (nodes.size()) {
			int root = valid_indeg();
			if (root == -1) {
				isTree = false;
			}
			else {
				trace(root, root);
				all_visited(root);
			}
		}
		print_result();
	}

}

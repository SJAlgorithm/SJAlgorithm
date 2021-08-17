#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct node {
	int number;
	bool can_make = false;
	vector<vector<int>> indeg;
	vector<int> indeg_cnt;
	vector<int> edge;
}Node;

int n, m, r,l;
Node node[200001];
vector<int> result;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		node[i].number = i;
	}
	for (int i = 0; i < m; i++) {
		int k, r;
		vector<int> x;
		cin >> k;
		x.resize(k);
		for (int j = 0; j < k; j++) {
			cin >> x[j];
		}
		cin >> r;
		node[r].indeg.push_back(x);
		node[r].indeg_cnt.push_back(x.size());
		for (int to : x) {
			node[to].edge.push_back(r);
		}
	}

	queue<int> q;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int data;
		cin >> data;
		node[data].can_make = true;
		result.push_back(data);
		q.push(data);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : node[now].edge) {
			if (node[next].can_make) continue;

			//레시피들의 위상정렬 실시
			for (int i = 0; i < node[next].indeg.size(); i++) {
				if (node[next].can_make) break;
				for (int j = 0; j < node[next].indeg[i].size(); j++) {
					if (now == node[next].indeg[i][j]) {
						node[next].indeg[i][j] = -1;
						node[next].indeg_cnt[i]--;
						if (!node[next].indeg_cnt[i]) {
							node[next].can_make = true;
							break;
						}
					}
				}
			}
			//실시후 가능하면 push
			if (node[next].can_make) {
				result.push_back(next);
				q.push(next);
			}
		}
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	

	return 0;
}
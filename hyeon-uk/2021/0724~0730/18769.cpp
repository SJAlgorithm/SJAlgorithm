#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

pair<int,int> parent[501][501];
vector<pair<pair<pair<int,int>, pair<int,int>>,int>> edge;
int r, c,t;

bool compare(pair<pair<pair<int, int>, pair<int, int>>, int> a, pair<pair<pair<int, int>, pair<int, int>>, int> b) {
	return a.second < b.second;
}

pair<int,int> find(pair<int,int> a) {
	if (a == parent[a.first][a.second]) {
		return a;
	}
	else {
		return parent[a.first][a.second]=find(parent[a.first][a.second]);
	}
}

void union_parent(pair<int,int> a, pair<int, int> b) {
	a = find(a);
	b = find(b);

	if (a < b) {
		parent[b.first][b.second] = a;
	}
	else {
		parent[a.first][a.second] = b;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> r >> c;
		edge.clear();
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				parent[i][j] = { i,j };
			}
		}

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j < c; j++) {
				int cost;
				cin >> cost;
				edge.push_back({ {{i,j},{i,j + 1}},cost });
			}
		}

		for (int i = 1; i < r; i++) {
			for (int j = 1; j <= c; j++) {
				int cost;
				cin >> cost;
				edge.push_back({ {{i,j},{i + 1,j}},cost });
			}
		}

		sort(edge.begin(), edge.end(), compare);
		int total = 0;
		for (int i = 0; i < edge.size(); i++) {
			pair<int, int> a, b;
			int cost;
			a = edge[i].first.first;
			b = edge[i].first.second;
			cost = edge[i].second;
			if (find(a) != find(b)) {
				union_parent(a, b);
				total += cost;
			}
		}
		cout << total << "\n";
	}

	return 0;
}

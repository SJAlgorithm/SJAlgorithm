#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>//memset
using namespace std;

vector<vector<int>> v;
vector<int> indegree, build;
int n, m, k;
bool cheat = false;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	v.resize(n + 1);
	indegree.resize(n + 1);
	build.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		indegree[to]++;
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			//이전 지어져있어야 되는 건물이 건설 o
			if (indegree[y] == 0) {
				build[y]++;
				//처음 만들어진 거라면 이것과 연결된 노드들의 진입차수 --
				if (build[y] == 1) {
					for (int j = 0; j < v[y].size(); j++) {
						indegree[v[y][j]]--;
					}
				}
			}
			//이전 지어져 있어야되는 건물이 아직 건설 x
			else {
				cheat = true;
				break;
			}
		}
		else {
			if (build[y] > 0) {
				build[y]--;
				//파괴하고 나서 건물이 없다면, 연결된 노드의 진입차수 ++
				if (build[y] == 0) {
					for (int j = 0; j < v[y].size(); j++) {
						indegree[v[y][j]]++;
					}
				}
			}
			else {
				cheat = true;
				break;
			}
		}
	}
	cheat ? cout << "Lier!\n": cout << "King-God-Emperor\n";
	return 0;
}
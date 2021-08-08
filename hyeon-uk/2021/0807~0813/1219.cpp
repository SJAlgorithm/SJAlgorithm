#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

int n, m, st, en;
const long long MAX = LLONG_MAX;
vector<pair<int, int>> v[101];
int money[101] = { 0 };
bool visited[101] = { 0 };

void bf() {
	long long dist[101];
	for (int i = 0; i < n; i++) {
		dist[i] = -MAX;
	}
	dist[st] = money[st];

	queue<int> cycleq;
	bool update;
	for (int k = 0; k < n; k++) {
		update = false;
		for (int i = 0; i < n; i++) {
			if (dist[i] != -MAX) {
				for (auto j : v[i]) {
					int next = j.first;
					int next_cost = money[next]-j.second;

					if (dist[next] < dist[i] + next_cost) {
						dist[next] = dist[i] + next_cost;
						update = true;
						if (k == n - 1) {
							//사이클 체크
							cycleq.push(i);
						}
					}
				}
			}
		}
		if (!update) {
			break;
		}
	}
	//사이클에서 목적지까지 도달가능한지
	bool GeeCheck = false;
	while (!cycleq.empty()) {
		int now = cycleq.front();
		cycleq.pop();

		if (visited[now]) continue;

		visited[now] = true;

		for (auto i : v[now]) {
			int next = i.first;

			if (next == en) {
				GeeCheck = true;
				break;
			}
			else if(!visited[next]){
				cycleq.push(next);
			}
		}
	}
	if (dist[en] == -MAX) {
		cout << "gg\n";
	}
	else {
		if (GeeCheck) {
			cout << "Gee\n";
		}
		else {
			cout << dist[en] << "\n";
		}
	}
	return ;
}

void input() {
	cin >> n >> st >> en >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
}

void solve() {
	input();
	bf();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
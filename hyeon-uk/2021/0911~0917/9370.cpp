#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX	987654321
using namespace std;

typedef pair<int, int> pii;

int T;
int n, m, t;
int s, g, h;

void input(vector<pii> *maze,vector<int>& check) {
	cin >> n >> m >> t;
	cin >> s >> g >> h;
	check.resize(t);
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		maze[a].push_back({ b,d });
		maze[b].push_back({ a,d });
	}
	for (int i = 0; i < t; i++) {
		cin >> check[i];
	}
	sort(check.begin(), check.end());
}

bool trace(int a, int b) {
	return ((a == g && b == h) || (a == h && b == g));
}

vector<int> dijk(vector<pii> *maze,int st) {
	vector<int> dist(n+1,MAX);
	queue<pii> q;
	dist[st] = 0;
	q.push({ st,0 });
	while (!q.empty()) {
		int now = q.front().first;
		int distance = q.front().second;
		q.pop();

		if (distance > dist[now]) {
			continue;
		}

		for (auto k : maze[now]) {
			int next = k.first;
			int cost = k.second+distance;

			if (cost < dist[next]) {
				q.push({ next, cost });
				dist[next] = { cost };
			}
		}
	}

	return dist;
}

int main() {
	cin >> T;
	while (T--) {
		vector<pii> maze[2001];
		vector<int> check;
		input(maze,check);
		vector<int> start=dijk(maze, s);
		vector<int> vh = dijk(maze, h);
		vector<int> vg = dijk(maze, g);

		for (int c : check) {
			int dist = start[c];// s->목적지까지의 최단거리
			int dist_shgc = start[h] + vh[g] + vg[c]; //s->h->g->c까지의 최단거리
			int dist_sghc = start[g] + vg[h] + vh[c]; //s->g->h->c까지의 최단거리
			if (dist == dist_shgc || dist == dist_sghc) {
				cout << c << " ";
			}
		}
		cout << "\n";
	}
}

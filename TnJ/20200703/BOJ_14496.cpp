// <그대, 그머가 되어> - BOJ_14496
// BFS

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define xx first
#define yy second

int A, B, N, M;
vector<int> v[1001];
bool vi[1001]{};

void solve(int st) {
	queue<pii> q;
	q.push({0,st});
	vi[st] = true;

	while (!q.empty()) {
		int cd = q.front().xx;
		int cp = q.front().yy;
		q.pop();

		if (cp == B) { cout << cd; exit(0); }

		for (int i = 0; i < v[cp].size(); i++) {
			int np = v[cp][i];
			if (vi[np]) continue;
			q.push({cd+1,np});
			vi[np] = true;
		}
	}
    cout<<-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> A >> B >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve(A);
}
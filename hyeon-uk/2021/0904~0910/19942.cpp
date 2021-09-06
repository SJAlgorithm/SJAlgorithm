#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 987654321
using namespace std;

typedef struct node{
	int num, p, f, s, v, c;
}node;

int n, mp, mf, ms, mv,ret=MAX;
vector<int> ret_v;
vector<int> temp_v;
vector<node> foods;
bool visited[15];

int isOver() {
	int sp, sf, ss, sv, sc;
	sp = sf = ss = sv = sc = 0;
	temp_v.clear();
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			sp += foods[i].p;
			sf += foods[i].f;
			ss += foods[i].s;
			sv += foods[i].v;
			sc += foods[i].c;
			temp_v.push_back(foods[i].num);
		}
	}
	if (sp >= mp && sf >= mf && ss >= ms && sv >= mv) {
		return sc;
	}
	else {
		return -1;
	}
}

void dfs(int ind) {
	int sum=isOver();
	if (sum!=-1&&ret>sum) {
		ret = min(ret, sum);
		ret_v = temp_v;
	}

	if (ind == n) {
		return;
	}
	visited[ind] = true;
	dfs(ind + 1);
	visited[ind] = false;
	dfs(ind + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		int p, f, s, v, c;
		cin >> p >> f >> s >> v >> c;
		foods.push_back({ i + 1,p,f,s,v,c });
	}
	dfs(0);
	if (ret == MAX) {
		cout << -1;
	}
	else {
		cout << ret << "\n";
		for (int i = 0; i < ret_v.size(); i++) {
			cout << ret_v[i] << " ";
		}
	}
	return 0;
}
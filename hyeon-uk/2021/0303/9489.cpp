#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, k;
int parent[1000001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	while (n!=0&&k!=0) {
		vector<int> v;
		queue<int> q;
		v.resize(n);
		int flag = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			q.push(v[i]);
		}

		int pind = 0;
		//루트의 부모를 0으로 설정
		parent[v[pind]] = 0;
		q.pop();

		//부모를 설정중
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			parent[now] = v[pind];
			//연속된 수가 아니면 부모 인덱스 ++
			if (q.size() != 0 && now + 1 != q.front()) {
				pind++;
			}
		}

		int cnt = 0;
		parent[v[0]] = 0;
		//루트의 직계자식이 아닐때
		if (parent[ parent[k]] != 0) {

			//조부모가 같고 부모가 같지 않을때 ++
			for (int i = 0; i < n; i++) {
				int now = v[i];
				if (v[i] == k) continue;
				if (parent[parent[now]] == parent[parent[k]] && parent[now] != parent[k]) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		cin >> n >> k;
	}
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,t,k,q;
int cnt[100001] = { 0 };
vector<pair<int, int>> edge;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		edge.push_back({ a,b });
		cnt[a]++;
		cnt[b]++;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t>>k;
		if (t == 1) {
			if (cnt[k] >=2) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
		else {
			int a = edge[k-1].first;
			int b = edge[k-1].second;
			if (cnt[a] >= 1 && cnt[b] >= 1) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}

}
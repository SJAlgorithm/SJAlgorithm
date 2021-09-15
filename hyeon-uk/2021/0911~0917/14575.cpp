#include<iostream>
#include<algorithm>
#include<vector>
#define MAX	1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, t;
vector<pii> v;

bool can(int s) {
	ll more = 0;
	ll min_sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first > s) {
			return false;
		}
		more += (min(s, v[i].second)-v[i].first);
		min_sum += v[i].first;
	}
	if (more >= t - min_sum) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	ll min_sum = 0;
	ll max_sum = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		min_sum += l;
		max_sum += r;
		right = max(right, r);
		v.push_back({ l,r });
	}
	if (t < min_sum||max_sum<t) {
		cout << -1;
		return 0;
	}
	int answer = MAX;
	while (left <= right) {
		int s = (left + right) / 2;
		if (can(s)) {
			answer = min(answer,s);
			right = s - 1;
		}
		else {
			left = s+1;
		}
	}

	cout << answer;
}

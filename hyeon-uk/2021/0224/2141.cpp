#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
int n;
vector<pair<ll, ll>> v;
vector<ll> s;
int main() {
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll x, a;
		cin >> x >> a;
		v.push_back({ x,a });
	}

	sort(v.begin(), v.end());

	s.resize(n);
	s[0] = v[0].second;
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + v[i].second;
	}

	int left = 0;
	int right = n - 1;
	ll result = 1000000001;
	while (left <= right) {
		int middle = (left + right) / 2;
	
		ll leftsum = s[middle];
		ll rightsum = s[n - 1] - s[middle];

		if (leftsum >= rightsum) {
			right = middle - 1;
			result = min(result, v[middle].first);
		}
		else {
			left = middle + 1;
		}
	}
	cout << result;
}

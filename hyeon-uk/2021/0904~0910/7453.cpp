#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

vector<long long> a, b, c, d;
vector<long long> e, f;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	d.resize(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			e.push_back(a[i] + b[j]);
			f.push_back(c[i] + d[j]);
		}
	}

	sort(e.begin(), e.end());
	sort(f.begin(), f.end());
	long long cnt = 0;
	for (long long i = 0; i < e.size(); i++) {
		long long low = lower_bound(f.begin(), f.end(), -e[i]) - f.begin();
		long long high = upper_bound(f.begin(), f.end(), -e[i]) - f.begin();
		if (-f[low] == e[i]) {
			cnt += (high - low);
		}
	}
	cout << cnt;
}
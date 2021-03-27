#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, l, cnt = 0;
	cin >> m >> n >> l;
	for (long long i = 0; i < m; i++) {
		long long data;
		cin >> data;
		M.push_back(data);
	}
	sort(M.begin(), M.end());
	for (long long i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;

		long long ind = lower_bound(M.begin(), M.end(), x) - M.begin();
		if (abs(M[ind] - x) + y <= l) cnt++;
		else if (ind - 1 >= 0 && abs(M[ind - 1] - x) + y <= l) cnt++;
	}
	cout << cnt;
}

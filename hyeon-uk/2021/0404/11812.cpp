#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

long long n, k, q;

long long parent(long long n,long long k) {
	return (n + k-2) / k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> q;
	for (int i = 0; i < q; i++) {
		long long x, y;
		cin >> x >> y;

		if (k == 1) {
			cout << abs(x - y) << "\n";
			continue;
		}

		int result = 0;


		while (x != y) {
			while (x >y) {
				result++;
				x = parent(x, k);
			}
			while (y > x) {
				result++;
				y = parent(y, k);
			}
		}
		cout << result << "\n";
	}
}

/*
자신의 부모= (N+K-2)/K
*/


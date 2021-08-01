#include<iostream>
#include <algorithm>
#include<vector>
#include<utility>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int left = 1;
	int right = k;
	int answer = 1;
	while (left <= right) {
		int m = (left + right) >> 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(m / i, n);
		}
		if (cnt < k) {
			left = m + 1;
		}
		else {
			answer = m;
			right = m - 1;
		}
	}
	cout <<  answer;
	return 0;
}
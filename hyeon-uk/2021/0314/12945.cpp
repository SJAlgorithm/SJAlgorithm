#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> box;
int main() {
	cin >> n;
	box.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
	sort(box.begin(), box.end());
	int right = n / 2;
	int left = 0;

	for (int i = 0; i < n/2; i++) {
		int ind = lower_bound(box.begin(), box.end(), box[i] * 2) - box.begin();
		if (ind == n) break;
		if (ind <= right) {
			left++;
			right++;
		}
		else {
			left++;
			right = ind + 1;
		}

		if (right == n) break;
	}

	cout << n - left;
}
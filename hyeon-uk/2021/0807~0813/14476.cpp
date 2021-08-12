#include <iostream>
#include<algorithm>
using namespace std;

int gcd_left[1000001], gcd_right[1000001],arr[1000001];
int n;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) {
			gcd_left[i] = arr[i];
		}
		if (i == n) {
			gcd_right[i] = arr[i];
		}
	}

	for (int i = 2; i <= n; i++) {
		gcd_left[i] = gcd(arr[i], gcd_left[i - 1]);
		gcd_right[n - i+1] = gcd(arr[n - i+1], gcd_right[n - i+2]);
	}
	int maxValue = gcd_left[n];
	int index = -1;
	for (int i = 1; i <= n; i++) {
		int g = gcd(gcd_left[i - 1], gcd_right[i + 1]);

		if (maxValue < g) {
			int now = arr[i];
			if (arr[i] % g != 0) {
				maxValue = g;
				index = i;
			}
		}
	}
	if (index == -1) {
		cout << "-1\n";
	}
	else {
		cout << maxValue << " " << arr[index];
	}
	return 0;
}
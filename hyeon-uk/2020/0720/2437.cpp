#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < v[i]) break;
		sum += v[i];
	}
	cout << sum +1;
	return 0;
}

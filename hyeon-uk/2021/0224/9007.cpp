#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<limits.h>
#define INF INT_MAX;
using namespace std;

int arr1[1000], arr2[1000];
vector<int> v1, v2, v3;
int t, n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		v1.clear();
		v2.clear();
		int n, m;
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v1.push_back(arr1[i] + arr2[j]);
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v2.push_back(arr1[i] + arr2[j]);
			}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int result, gap;
		result = gap = INF;
		for (int i = 0; i < n*n; i++) {
			int val = m - v1[i];
			int ind = lower_bound(v2.begin(), v2.end(), val) - v2.begin();
			if (ind == n * n) ind--;
			int total = v1[i] + v2[ind];
			int tgap = abs(m - total);
			if (gap == tgap && result > total) {
				result = total;
			}
			else if (gap > tgap) {
				gap = tgap;
				result = total;
			}
			if (ind != 0) {
				total = v1[i] + v2[ind - 1];
				tgap = abs(m - total);
				if (gap == tgap && result > total) {
					result = total;
				}
				else if (gap > tgap) {
					gap = tgap;
					result = total;
				}
			}
		}
		cout << result << "\n";
	}
	return 0;
}

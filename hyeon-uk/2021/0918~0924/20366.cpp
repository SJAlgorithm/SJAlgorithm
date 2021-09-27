#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX	2000000001
using namespace std;
typedef pair<int, int> pii;
vector<pair<pii,int>> sum_v;
int n;
vector<int> arr;

bool compare(pair<pii, int> a, pair<pii, int> b) {
	return a.second < b.second;
}

int main() {
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum_v.push_back({ {i,j},arr[i] + arr[j] });
		}
	}
	sort(sum_v.begin(), sum_v.end(), compare);
	int ret = MAX;
	for (int i = 0; i < sum_v.size()-1; i++) {
		for (int j = i + 1; j < sum_v.size(); j++) {
			int i1 = sum_v[i].first.first;
			int j1 = sum_v[i].first.second;
			int c1 = sum_v[i].second;

			int i2 = sum_v[j].first.first;
			int j2 = sum_v[j].first.second;
			int c2 = sum_v[j].second;

			if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
				ret = min(ret, abs(c1 - c2));
				break;
			}
		}
	}
	cout << ret;

	return 0;
}
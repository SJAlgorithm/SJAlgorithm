#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m,paper,gray;
vector<pair<int, int>> point;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	cin >> paper;
	cin >> gray;
	int left = 0;
	for (int i = 0; i < gray; i++) {
		int r, c;
		cin >> r >> c;
		point.push_back({ r,c });
		left = max(left, r);
	}

	sort(point.begin(), point.end(),compare);
	int right = n;
	while (left <= right) {
		int size = (left + right)/2;
		int cnt = 1;
		int nowx = point[0].second;
		for (int i = 1; i < gray; i++) {
			if (point[i].second < nowx + size) continue;
			else {
				nowx = point[i].second;
				cnt++;
			}
		}
		if (cnt <= paper) {
			right = size - 1;
		}
		else {
			left = size + 1;
		}
	}
	cout << left << "\n";

	return 0;
}

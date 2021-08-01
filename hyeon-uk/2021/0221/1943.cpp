#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t=3;
	vector<pair<int, int>> p;
	while (t--) {
		p.clear();
		int sum=0;
		int n;
		cin >> n;
		bool canDiv[50001] = { 0 };
		for (int i = 0; i < n; i++) {
			int money, cnt;
			cin >> money >> cnt;
			sum += (money*cnt);
			p.push_back({ money,cnt });
		}
		if (sum % 2) {
			cout << 0 << "\n";
			continue;
		}
		sort(p.begin(), p.end());

		int mid = sum / 2;
		canDiv[0] = true;
		for (int i = p.size() - 1; i >= 0;i--) {
			int money = p[i].first;
			int cnt = p[i].second;

			for (int j = mid; j >= 0; j--) {
				if (canDiv[j]) {
					for (int k = 1; k <= cnt; k++) {
						if(j+money*k<=50000) canDiv[j + money * k] = true;
					}
				}
			}
		}
		if (canDiv[mid]) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}

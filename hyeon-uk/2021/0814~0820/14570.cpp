#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

pair<int, int> arr[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		arr[i].first = u;
		arr[i].second = v;
	}

	long long k;
	cin >> k;
	int now = 1;
	//k가 홀수면 왼쪽으로, 짝수면 오른쪽으로 떨어짐
	while (true) {
		if (arr[now].first == -1 && arr[now].second == -1) {
			break;
		}
		else if (arr[now].first == -1) {
			now = arr[now].second;
		}
		else if (arr[now].second == -1) {
			now = arr[now].first;
		}
		else {
			if (k % 2) {
				now = arr[now].first;
				k = k / 2 + 1;
			}
			else {
				k /= 2;
				now = arr[now].second;
			}
		}
	}
	cout << now;
	return 0;
}
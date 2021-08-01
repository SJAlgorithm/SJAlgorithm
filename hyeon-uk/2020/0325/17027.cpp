#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100][3];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	int result = 0;
	for (int k = 1; k <= 3; k++) {
		int now = k;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int a = arr[i][0];
			int b = arr[i][1];
			int g = arr[i][2];
			if (now == a) {
				now = b;
			}
			else if (now == b) {
				now = a;
			}
			
			if (now == g) {
				cnt++;
			}
		}
		result = max(result, cnt);
	}
	cout << result;
}

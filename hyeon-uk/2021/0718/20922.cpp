#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[200000];
int cnt[100001];
int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int st = 0;
	int end = 0;
	int result = 0;
	while (st < n) {
		if (cnt[arr[st]] != k) {
			cnt[arr[st]]++;
			st++;
		}
		else {
			cnt[arr[end]]--;
			end++;
		}
		result = max(result, st - end);
	}
	cout << result << "\n";
	return 0;
}
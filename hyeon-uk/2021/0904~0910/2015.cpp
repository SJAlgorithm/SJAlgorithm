#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

map<int, long long> sub_sum;
int arr[200001] = { 0 }, psum[200001] = { 0 };
long long n, k,answer=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
		if (psum[i] == k) answer++;
	}
	for (int i = 1; i <= n; i++) {
		answer += sub_sum[psum[i] - k];
		sub_sum[psum[i]]++;
	}
	cout << answer;
	return 0;
}
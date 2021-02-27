#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n;
int rk[10001];
int sw[10001];
int check[10001];//check[i]=j i전구 앞에 올 전구의 번호
vector<int> dp;
priority_queue<int> result;
int main() {
	cin >> n;
	//해당 스위치로 이어진 전구의 순위 저장
	for (int i = 1; i <= n; i++) {
		cin >> sw[i];
		rk[sw[i]] = i;
	}
	//앞쪽 전구부터 시작하여 가장 긴 증가하는 수열을 구함
	//O(nlogn)
	for (int i = 1; i <= n; i++) {
		int data;
		cin >> data;
		//만약 비어있거나 저장된것보다 크면 push
		if (dp.empty() || dp.back() < rk[data]) {
			if (dp.empty()) check[rk[data]] = -1;
			else check[rk[data]] = dp.back();
			dp.push_back(rk[data]);
		}
		//입력한게 증가하고있는수열보다 작은경우
		//이분탐색으로 data보다 큰 가장 작은 정수의 위치에 입력
		else {
			int ind = lower_bound(dp.begin(), dp.end(), rk[data]) - dp.begin();
			dp[ind] = rk[data];
			check[rk[data]] = ind ? dp[ind - 1] : -1;

		}
	}
	cout << dp.size() << "\n";

	int d = dp.back();

	while (d > 0) {
		result.push(-sw[d]);
		d = check[d];
	}
	while (!result.empty()) {
		cout << -result.top()<<" ";
		result.pop();
	}
}
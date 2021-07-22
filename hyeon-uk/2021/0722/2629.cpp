#include <iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

bool can_check[31][40001] = { 0 };
vector<int> ball;
int n, m;

void dp(int index,int total) {
	if (index > n) return;
	if (can_check[index][total]) return;
	can_check[index][total] = true;

	dp(index + 1, total + ball[index]);
	dp(index + 1, total);
	dp(index + 1, abs(total - ball[index]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	ball.resize(n+1);
	for (int i = 0; i < n; i++) {
		cin >> ball[i];
	}
	dp(0, 0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		cout << (can_check[n][data] ? "Y ":"N ");
	}

	return 0;
}
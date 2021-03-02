#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, w;
vector<int> v;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> w;

	v.resize(n + 1);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]++;
	}
	
	double cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (v[i] == 1) cnt++;
	}
	cout.precision(6);

	cout <<fixed<< w / cnt << "\n";
}
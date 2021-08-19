#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	map<string, bool> ma;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		ma[input] = true;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		if (ma[input]) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
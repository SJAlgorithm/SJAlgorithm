#include<iostream>
#include<algorithm>
using namespace std;

int t;
int member[11][11] = { 0 };
bool check[11] = { 0 };
int ret = 0;

void dfs(int mem,int sum) {
	if (mem == 11) {
		ret = max(ret, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!check[i]&&member[mem][i]!=0) {
			check[i] = true;
			dfs(mem + 1,sum+member[mem][i]);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--) {
		ret = 0;
		for (int i = 0; i < 11; i++) {
			check[i] = false;
			for (int j = 0; j < 11; j++) {
				cin >> member[i][j];
			}
		}
		dfs(0,0);
		cout << ret << "\n";
	}
	return 0;
}

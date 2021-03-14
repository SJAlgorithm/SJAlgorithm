#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool check[901][901];
vector<int> result;
int k, n, f;
bool flag = false;
void solve(int d) {
	result.push_back(d);

	if (result.size() == k) {
		flag = true;
		return;
	}

	for (int i = d + 1; i <= n; i++) {
		//i번 친구가 현재까지 저장된 친구들과 모두 친구인지 체크
		if (check[d][i]) {
			bool flag1 = true;
			
			for (int j = 0; j < result.size(); j++) {
				if (!check[i][result[j]]) {
					flag1 = false;
					break;
				}
			}
			

			if (flag1) {
				solve(i);
			}
			if (flag) {
				return;
			}
		}
	}
	result.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n >> f;

	for (int i = 0; i < f; i++) {
		int a, b;
		cin >> a >> b;
		check[a][b] = true;
		check[b][a] = true;
	}

	for (int i = 1; i <= n; i++) {
		solve(i);
		if (flag) {
			for (int j = 0; j < result.size(); j++) {
				cout << result[j] << "\n";
			}
			break;
		}
	}
	
	if (!flag) {
		cout << "-1\n";
	}

	return 0;
}
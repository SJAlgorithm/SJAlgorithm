#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define MAX 987654321
using namespace std;

long long cost[101][101] = { 0 };
int n, m;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cost[i][j] = 0;
			else cost[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		int st, end, w;
		cin >> st >> end >> w;
		if (cost[st][end] > w) {
			cost[st][end] = w;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (cost[j][i] + cost[i][k] < cost[j][k]) {
					cost[j][k] = cost[j][i] + cost[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == MAX) cout << "0 ";
			else {
				cout << cost[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}

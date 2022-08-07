// <외판원 순회> - BOJ_2098
// 비트마스킹, DP(탑 다운), 그래프이론

#include<bits/stdc++.h>
#define MAX 1e9
#define CITY 16
using namespace std;

int n;
int adj[CITY][CITY]{};
int d[1 << CITY][CITY]{};

int TSP(int visit, int now){
	visit |= (1 << now);
	
	if (visit == (1 << n) - 1) {
		if (adj[now][0] > 0){
			return adj[now][0];
		}
		return MAX;
	}

	int& ret = d[visit][now];
	if (ret > 0) return ret;
	ret = MAX;

	for (int i = 0; i < n; i++){
		if (i != now && (visit&(1<<i))==0 && adj[now][i] > 0){
			int temp = TSP(visit, i) + adj[now][i];
			if (ret > temp)
				ret = temp;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	
	int ans = TSP(0, 0);
	if (ans == MAX) cout<<-1;
	else cout<<ans;
}
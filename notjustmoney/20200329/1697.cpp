// "¼û¹Ù²ÀÁú", https://www.acmicpc.net/problem/1697
// writen in C++
// 2020. 03. 29
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
vector<pair<bool, int>> v(100001);
int main() {
	int N, K;
	int cnt1=1, cnt2=0, sec=0;
	scanf("%d %d", &N, &K);
	v[N].first = true;
	v[N].second = 0;
	queue<int> q;
	q.push(N);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		if(x == K) break;
		int position[3] = {x-1, x+1, x*2};
		for(int i = 0; i < 3; i++) {
			if(position[i] >= 0 && position[i] <= 100000 && !v[position[i]].first) {
				v[position[i]].first = true;
				v[position[i]].second = v[x].second + 1;
				q.push(position[i]);
			}
		}
	}
	printf("%d\n", v[K].second);
	return 0;	
}

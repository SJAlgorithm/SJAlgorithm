// "스타트링크", https://www.acmicpc.net/problem/5014
// writen in C++
// 2020. 04.10
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int v[1000054];
int main() {
	int f, s, g, u, d;
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	queue<pair<int, int> > q;
	q.push({s, 0});
	v[s] = true;
	while(!q.empty()) {
		pair<int, int> cur=q.front(); q.pop();
		if(cur.first == g) {
			printf("%d\n", cur.second);	
			return 0;
		}
		if(cur.first+u <= f && !v[cur.first+u]) {
			q.push({cur.first+u, cur.second+1});
			v[cur.first+u] = true;
		}
		if(cur.first-d >= 1 && !v[cur.first-d]) {
			q.push({cur.first-d, cur.second+1});
			v[cur.first-d] = true;
		}
	}
	printf("use the stairs\n");	
	return 0;	
}

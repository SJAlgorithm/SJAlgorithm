// "¹ÂÅ»¸®½ºÅ©", https://www.acmicpc.net/problem/12869
// writen in C++
// 2020. 04.04
// notjustmoney
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int N, dp[66][66][66];
int go(int x, int y, int z) {
	if(!x&&!y&&!z) return 0;
	int &ret = dp[x][y][z];
	if(ret != -1) return ret;
	ret = INF;
	ret = min(ret, go(max(x-9, 0), max(y-3, 0), max(z-1, 0))+1);
	ret = min(ret, go(max(x-9, 0), max(y-1, 0), max(z-3, 0))+1);
	ret = min(ret, go(max(x-3, 0), max(y-9, 0), max(z-1, 0))+1);
	ret = min(ret, go(max(x-3, 0), max(y-1, 0), max(z-9, 0))+1);
	ret = min(ret, go(max(x-1, 0), max(y-9, 0), max(z-3, 0))+1);
	ret = min(ret, go(max(x-1, 0), max(y-3, 0), max(z-9, 0))+1);
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	int scv[3] = {0, };
	for(int i = 0; i < N; i++) scanf("%d", scv+i);
	printf("%d\n", go(scv[0], scv[1], scv[2]));	
	return 0;	
}

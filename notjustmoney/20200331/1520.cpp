// "내리막길", https://www.acmicpc.net/problem/1520
// writen in C++
// 2020. 04.10
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int miro[504][504];
int dp[504][504];
int m, n;
int dx[4] = { 0 , 0, -1, 1} ;
int dy[4] = { -1, 1, 0, 0 };
int go(int y, int x) {
	if(!y && !x) return 1;
	int &ret=dp[y][x];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0; i<4; i++) {
		int cy=dy[i]+y;
		int cx=dx[i]+x;
		if(x>=0 && x<n && y>=0 && y<m && miro[y][x] < miro[cy][cx])
			ret += go(cy, cx);	
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &m, &n);
	for(int i=0; i<m; i++) 
	for(int j=0; j<n; j++)
		scanf("%d", &miro[i][j]);
	printf("%d\n", go(m-1, n-1));
	return 0;	
}

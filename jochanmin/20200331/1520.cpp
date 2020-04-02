#include<bits/stdc++.h>

using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
int a[501][501];
int dp[501][501];
int go(int x, int y) {
    if (x == 0 && y == 0)return 1;
    int &ret = dp[x][y];
    if (ret != -1)return ret;
    ret = 0;
    for (int i = 0; i < 4; i++) {
        int cx = dx[i] + x;
        int cy = dy[i] + y;
        if (0 <= x&&x < n && 0 <= y&&y < m){
			if (a[x][y] < a[cx][cy])
				ret += go(cx, cy);
		}
    }
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    printf("%d\n", go(n - 1, m - 1));
    return 0;
}

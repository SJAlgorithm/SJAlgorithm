#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int map[504][504];
int dp[504][504];
int cnt;

int go(int cy, int cx) {
    if (cy == N && cx == M) {
        return 1;
    }
    int &ret = dp[cy][cx];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
            if (map[ny][nx] < map[cy][cx]) {
                ret += go(ny, nx);
            }
        }
    }
    return ret;
}

int main() {
    for (int i = 0; i < 504; i++) {
        for (int j = 0; j < 504; j++) {
            dp[i][j] = -1;
        }
    }
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", go(1, 1));
    return 0;
}


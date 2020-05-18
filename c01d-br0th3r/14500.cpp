#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[504][504];
int visited[504][504];
int ret;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int cy, int cx, int cnt, int total) {
    if (cnt == 3) {
        ret = max(ret, total);
        return ;
    }
    
    visited[cy][cx] = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        
        if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                dfs(ny, nx, cnt+1, total+arr[ny][nx]);
                visited[ny][nx] = 0;
            }
        }
    }
    
    visited[cy][cx] = 0;
}

void fuckBlock(int y, int x) {
    if (y+2<N && x+1<M) {
        ret = max(ret, arr[y][x] + arr[y+1][x] + arr[y+2][x] + arr[y+1][x+1]);
    }
    if (y+2<N && x+1<M) {
        ret = max(ret, arr[y+1][x] + arr[y][x+1] + arr[y+1][x+1] + arr[y+2][x+1]);
    }
    if (y+1<N && x+2<M) {
        ret = max(ret, arr[y][x+1] + arr[y+1][x] + arr[y+1][x+1] + arr[y+1][x+2]);
    }
    if (y+1<N && x+2<M) {
        ret = max(ret, arr[y][x] + arr[y][x+1] + arr[y][x+2] + arr[y+1][x+1]);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(i, j, 0, arr[i][j]);
            fuckBlock(i, j);
        }
    }
    
    printf("%d\n", ret);
    
    return 0;
}


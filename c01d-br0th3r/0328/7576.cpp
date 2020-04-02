#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int arr[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int M, N, ret = 0;
int flag = 0;

void bfs() {
    queue<pair<int, int>> q;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j]  == 1) q.push(pair<int, int>(i, j));
        }
    }
    
    while (!q.empty()) {
        int cx = q.front().first; // 3
        int cy = q.front().second; // 5
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (arr[nx][ny] == 0) {
                    q.push({nx, ny}));
                    arr[nx][ny] = arr[cx][cy] + 1;
                }
            }
        }
    }
    
}

int main() {
    scanf("%d %d", &M, &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    bfs();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                flag = 1;
                break;
            }
            if (arr[i][j] > ret) ret = arr[i][j];
        }
    }
    
    if (flag == 1) printf("-1\n");
    else printf("%d\n", ret - 1);
    
    return 0;
}


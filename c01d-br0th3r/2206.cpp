#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, M;
int arr[1004][1004];
int visited[1004][1004][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    while (!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int flag = q.front().second;
        // 0 이면 벽 뚫기 가능, 1이면 뚫고 온 것
        q.pop();

        if (cy == N-1 && cx == M-1) {
            return visited[cy][cx][flag]+1;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (arr[ny][nx] == 0 && visited[ny][nx][flag] == 0) {
                    q.push(make_pair(make_pair(ny, nx), flag));
                    visited[ny][nx][flag] = visited[cy][cx][flag] + 1;
                }
                else if (arr[ny][nx] == 1 && flag == 0) {
                    q.push(make_pair(make_pair(ny, nx), flag+1));
                    visited[ny][nx][flag+1] += visited[cy][cx][flag] + 1;
                }
            }
        }
    }
    
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    printf("%d\n", bfs());
    
    return 0;
}

/*
0 0 0 0 0
1 0 0 0 0
0 1 1 1 0
0 1 0 0 1
0 1 0 0 0

5 5
00000
10000
01110
01001
01000
*/


#include <cstdio>
#include <queue>
using namespace std;

struct map {
    int x, y, s;
    // s represents water(0) or hedgehog(1).
};

int r, c, sx, sy;
char a[51][51];
int dist[51][51];
queue<map> q;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs() {
    // Second, push position of hedgehog.
    q.push({sx, sy, 1});
    dist[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, s = q.front().s;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (a[nx][ny] == 'X' || dist[nx][ny]) continue;
            if (a[nx][ny] == 'D') {
                if (s == 0) continue;       // Water don't flood the cave.
                printf("%d\n", dist[x][y]); // Answer
                return;
            }
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny, s});
        }
    }
    printf("KAKTUS\n");
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%1s", &a[i][j]);
            if (a[i][j] == '*') {
                // First, push position of water.
                q.push({i, j, 0});
                dist[i][j] = 1;
            } else if (a[i][j] == 'S') {
                // Save position of hedgehog.
                sx = i, sy = j;
            }
        }
    }
    bfs();
    return 0;
}
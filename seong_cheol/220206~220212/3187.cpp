//
//  main.cpp
//  3187
//
//  Created by wi_seong on 2022/02/12.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int r, c;
char board[251][251];
bool vis[251][251];
int cnt1 = 0, cnt2 = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int i, int j) {
    int a = 0, b = 0;
    queue<pair<int, int>> Q;
    Q.push({i, j});
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
    
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == 'k') a++;
            if(board[nx][ny] == 'v') b++;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    if(a > b) cnt1 += a;
    else cnt2 += b;
}

void solution() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!vis[i][j]) bfs(i,j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> board[i][j];
    
    solution();
    cout << cnt1 << ' ' << cnt2;
    
    return 0;
}

//
//  main.cpp
//  21922
//
//  Created by wi_seong on 2022/01/16.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 2001
int ans = 0;
int N, M;
int res[MAX][MAX];
int arr[MAX][MAX];
bool isVisited[4][MAX][MAX];
queue<pair<pair<int, int>, int>> q;

int mov[4][2] = { {-1,0}, {0,1},{1,0} ,{0,-1} };

void bfs() {
    while(!q.empty()) {
        int dir = q.front().second;
        int nR = q.front().first.first + mov[dir][0];
        int nC = q.front().first.second + mov[dir][1];

        q.pop();
        if (nR < 0 || nR >= N || nC < 0 || nC >= M) continue;
        if (isVisited[dir][nR][nC]) continue;
        isVisited[dir][nR][nC] = true;
        res[nR][nC] = 1;
        if (arr[nR][nC] == 1 && dir % 2 == 1) continue;
        else if (arr[nR][nC] == 2 && dir % 2 == 0) continue;
        else if (arr[nR][nC] == 9) continue;
        else if (arr[nR][nC] == 3) {
            if (dir < 2) {
                dir = (dir + 1) % 2;
            } else {
                dir = 2 + (dir + 1) % 2;
            }
        }
        else if (arr[nR][nC] == 4) {
            if (dir == 0) dir = 3;
            else if (dir == 3) dir = 0;
            else if (dir == 1) dir = 2;
            else dir = 1;
        }
        q.push({{nR, nC}, dir});
    }
}

void solution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                res[i][j] = 1;
                for(int k = 0; k < 4; k++) {
                    isVisited[k][i][j] = true;
                    q.push({{i, j}, k});
                }
            }
        }
    }
    bfs();
}

void result_count() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ans += res[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;

    solution();
    result_count();
    cout << ans;
    
    return 0;
}

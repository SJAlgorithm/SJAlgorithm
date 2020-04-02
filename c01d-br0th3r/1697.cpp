#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, K;
int visited[200002] = { 0 };
int ret = 0;

bool isPossible(int a) {
    if (a >= 0 && a <= 200002) return true;
    else return false;
}

int bfs() {
    if (N >= K) return N - K;
    
    queue<pair<int, int>> q;
    q.push(pair<int, int>(N, 0));
    
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[now]  = 1;
        
        int plus = now + 1;
        int minus = now - 1;
        int multi = now * 2;
        
        if (plus == K || minus == K || multi == K) {
            cnt++;
            return cnt;
        }
        
        else {
            if (isPossible(plus) && visited[plus] == 0) {
                visited[plus] = 1;
                q.push(pair<int, int>(plus, cnt + 1));
            }
            
            if (isPossible(minus) && visited[minus] == 0) {
                visited[minus] = 1;
                q.push(pair<int, int>(minus, cnt + 1));
            }
            
            if (isPossible(multi) && visited[multi] == 0) {
                visited[multi] = 1;
                q.push(pair<int, int>(multi, cnt + 1));
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d\n", bfs());
    
    return 0;
}


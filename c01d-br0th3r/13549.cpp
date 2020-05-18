#include <bits/stdc++.h>
using namespace std;

#define MAX 200004

int N, K;
int visited[MAX];

int bfs() {
    if (N >= K) return N-K;
    
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cx == K) return cnt;
        visited[cx] = 1;
        if (cx * 2 <= MAX && !visited[cx*2]) {
            q.push(make_pair(cx*2, cnt));
            visited[cx*2] = 1;
        }
        
        if (cx - 1 >= 0 && !visited[cx-1]) {
            q.push(make_pair(cx-1, cnt+1));
            visited[cx-1] = 1;
        }
        
        if (cx + 1 <= MAX && !visited[cx+1]) {
            q.push(make_pair(cx+1, cnt+1));
            visited[cx+1] = 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d\n", bfs());
    return 0;
}


#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int arr[101][101];
int answer[101][101] = {0,};
int visited[101] = { 0 };
int N;

void bfs() {
    queue<int> q;
    
    for (int i = 0; i < N; i++) {
        q.push(i);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int j = 0; j < N; j++) {
                if (arr[current][j] == 1 && answer[i][j] == 0) {
                    q.push(j);
                    answer[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    bfs();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

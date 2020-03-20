#include <stdio.h>
#include <stdlib.h>

int map[1001][1001] = { 0 };
int DFSmap[1001] = { 0 };
int BFSmap[1001] = { 0 };
int queue[1001] = { 0 };

void DFS(int N, int v) {
    int i;
    
    DFSmap[v] = 1;
    printf("%d ", v);
    
    for (i = 1; i <= N; i++) {
        if (DFSmap[i] == 0 && map[v][i] == 1) {
            DFS(N, i);
        }
    }
}

void BFS(int N, int v) {
    int i, front = 0, rear = 1;
    int tmp;
    
    BFSmap[v] = 1;
    printf("%d ", v);
    
    queue[front] = v;
    
    while (1) {
        tmp = queue[front];
        front++;
        
        for (i = 1; i <= N; i++) {
            if (BFSmap[i] == 0 && map[tmp][i] == 1) {
                queue[rear] = i;
                rear++;
                BFSmap[i] = 1;
                printf("%d ", i);
            }
        }
        
        if (front >= rear) {
            break;
        }
    }
}

int main() {
    int N, M, v;
    int i, j, x, y;
    
    scanf("%d %d %d", &N, &M, &v);
    
    for (i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        map[y][x] = 1;
        map[x][y] = 1;
    }
    
    DFS(N, v);
    printf("\n");
    BFS(N, v);
    
    return 0;
}


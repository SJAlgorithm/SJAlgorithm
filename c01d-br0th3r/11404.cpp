#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define INF 987654321
#define NIL -1
#define MAX 104

int N, M;
int d[MAX][MAX];
int p[MAX][MAX];

void fw() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

int main() {
    int start, end, money;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = INF;
            if (i == j) d[i][j] = 0;
            p[i][j] = NIL;
        }
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &money);
        
        if (d[start][end] == INF) d[start][end] = money;
        else if (d[start][end] > money) d[start][end] = money;
        p[start][end] = start;
    }
    
    fw();
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (d[i][j] == INF) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


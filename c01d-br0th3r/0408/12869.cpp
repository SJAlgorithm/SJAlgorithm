#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define INF 987654321

int N;
int hp[64][64][64];
int scv[4];
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

int go(int hp1, int hp2, int hp3) {
    if (hp1 == 0 && hp2 == 0 && hp3 == 0)
        return 0;
    int &ret = hp[hp1][hp2][hp3];
    if (ret != INF) return ret;
    ret = INF;
    ret = min(ret, go(max(hp1-9, 0), max(hp2-3, 0), max(hp3-1, 0))+1);
    ret = min(ret, go(max(hp1-9, 0), max(hp2-1, 0), max(hp3-3, 0))+1);
    ret = min(ret, go(max(hp1-3, 0), max(hp2-9, 0), max(hp3-1, 0))+1);
    ret = min(ret, go(max(hp1-3, 0), max(hp2-1, 0), max(hp3-9, 0))+1);
    ret = min(ret, go(max(hp1-1, 0), max(hp2-9, 0), max(hp3-3, 0))+1);
    ret = min(ret, go(max(hp1-1, 0), max(hp2-3, 0), max(hp3-9, 0))+1);
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            for (int k = 0; k < 64; k++) {
                hp[i][j][k] = INF;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &scv[i]);
    }
    
    printf("%d\n", go(scv[0], scv[1], scv[2]));
    return 0;
}


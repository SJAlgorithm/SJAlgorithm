#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int L, C;
char arr[16];
char ret[16];
int visited[16] = { 0 };

void dfs(int start, int cnt) {
    int aeiouCnt = 0;
    int notAeiouCnt = 0;
    
    if (cnt == L - 1) {
        for (int i = 0; i < C; i++) {
            if (visited[i] == 1) {
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') aeiouCnt++;
                else notAeiouCnt++;
            }
        }
        
        if (aeiouCnt >= 1 && notAeiouCnt >= 2) {
            for (int i = 0; i < C; i++) {
                if (visited[i] == 1) printf("%c", arr[i]);
            }
            printf("\n");
        }
        return ;
    }
    
    for (int i = start; i < C; i++) {
        int nx = i + 1;
        visited[nx] = 1;
        if (nx < C && cnt < L) {
            dfs(nx, cnt + 1);
        }
        visited[nx] = 0;
    }
}

int main() {
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++) {
        getchar();
        scanf("%c", &arr[i]);
    }

    for (int i = 0; i < C - 1; i++) {
        for (int j = i + 1; j < C; j++) {
            if (arr[i] > arr[j]) {
                char tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    dfs(-1, -1);
    
    return 0;
}


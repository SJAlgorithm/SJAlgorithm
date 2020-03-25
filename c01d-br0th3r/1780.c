#include <stdio.h>

int N;
int arr[3000][3000] = { 0 };
int result[3] = { 0 };

void find(int x, int y, int n) {
    int i, j;
    int tmp;
    int flagM = 0, flagZ = 0, flagP = 0;
    
    if (n == 1) {
        result[arr[y][x] + 1]++;
        return ;
    }
    
    for (i = y; i < y+n; i++) {
        for (j = x; j < x+n; j++) {
            if (arr[i][j] == -1) {
                flagM = 1;
            }
            else if (arr[i][j] == 0) {
                flagZ = 1;
            }
            else {
                flagP = 1;
            }
        }
    }
    
    if (flagM == 1 && flagZ == 0 && flagP == 0) {
        result[0]++;
    }
    else if (flagM == 0 && flagZ == 1 && flagP == 0) {
        result[1]++;
    }
    else if (flagM == 0 && flagZ == 0 && flagP == 1) {
        result[2]++;
    }
    else {
        tmp = n/3;
        
        find(x, y, tmp);
        find(x+tmp, y, tmp);
        find(x+tmp*2, y, tmp);
        
        find(x, y+tmp, tmp);
        find(x+tmp, y+tmp, tmp);
        find(x+tmp*2, y+tmp, tmp);
        
        find(x, y+tmp*2, tmp);
        find(x+tmp, y+tmp*2, tmp);
        find(x+tmp*2, y+tmp*2, tmp);
    }
}

int main() {
    int i, j;
    
    scanf("%d", &N);
    
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    find(1, 1, N);
    
    for (i = 0; i < 3; i++) {
        printf("%d\n", result[i]);
    }
    
    return 0;
}


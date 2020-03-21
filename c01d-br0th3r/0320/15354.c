#include <stdio.h>

int main() {
    int N, i;
    int cnt = 1;
    char waiting[26];
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        getchar();
        scanf("%c", &waiting[i]);
    }
    
    for (i = 1; i < N; i++) {
        if (waiting[i - 1] == waiting[i]) {
            continue;
        }
        else {
            cnt++;
        }
    }
    
    printf("%d\n", cnt + 1);
    
    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j;
    int sum = 0;
    scanf("%d", &N);
    
    if (N == 1) {
        printf("0\n");
    }
    
    else {
        for (i = 1; i < N; i++) {
            sum += i;
            j = i;
            while (1) {
                sum += j % 10;
                if (j / 10 != 0) {
                    j /= 10;
                }
                else {
                    break;
                }
            }
            
            if (sum == N) {
                printf("%d\n", i);
                break;
            }
            
            if (i == N - 1) {
                printf("0\n");
            }
            
            sum = 0;
        }
    }
}


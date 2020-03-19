#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, j;
    int cnt = 0;
    
    scanf("%d", &N);
    
    for (i = 666; ; i++) {
        j = i;
        if (j % 1000 == 666) {
            cnt++;
        }
        
        else {
            while (1) {
                if (j / 1000 != 0) {
                    j /= 10;
                    if (j % 1000 == 666) {
                        cnt++;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        
        if (cnt == N) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}


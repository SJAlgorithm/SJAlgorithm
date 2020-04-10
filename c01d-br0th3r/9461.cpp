#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

long int d[101];

int main() {
    int N, t;
    scanf("%d", &N);
    
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;
    
    for (int i = 6; i < 101; i++) {
        d[i] = d[i-5]+d[i-1];
    }
    
    while (N--) {
        scanf("%d", &t);
        printf("%ld\n", d[t]);
    }
    return 0;
}


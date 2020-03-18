#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    int height;
    int weight;
    int rank;
} Person;

int main() {
    Person *p, tmp;
    int i, j, N;
    
    scanf("%d", &N);
    
    p = (Person *)malloc(sizeof(Person) * N);
    
    for (i = 0; i < N; i++) {
        scanf("%d %d", &p[i].weight, &p[i].height);
        p[i].rank = 1;
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (p[i].height < p[j].height && p[i].weight < p[j].weight) {
                p[i].rank++;
            }
        }
    }
    
    for (i = 0; i < N; i++) {
        printf("%d ", p[i].rank);
    }
    
    free(p);
    
    return 0;
}


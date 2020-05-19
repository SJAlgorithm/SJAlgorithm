#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int slime;
    int score = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &slime);
        v.push_back(slime);
    }
    sort(v.begin(), v.end(), compare);
    
    while (1) {
        int size = v.size();
        if (size == 1) break;
        
        int biggest = v[size-1];
        int nbiggest = v[size-2];
        int newSlime = biggest + nbiggest;
        score += biggest * nbiggest;
        v.pop_back();
        v.pop_back();
        v.push_back(newSlime);
        sort(v.begin(), v.end(), compare);
    }
    printf("%d\n", score);
    return 0;
}


#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int A, B, C;
int d[201][201][201];
int ret[201];
int k = 0;

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), C));
    
    while (!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        
        if (d[a][b][c] == 1) continue;
        d[a][b][c] = 1;
        
        if (a == 0) {
            ret[k] = c;
            k++;
        }
        
        if (a <= B-b) q.push(make_pair(make_pair(0, a+b), c));
        else q.push(make_pair(make_pair(a-(B-b), B), c));
        
        if (a <= C-c) q.push(make_pair(make_pair(0, b), c+a));
        else q.push(make_pair(make_pair(a-(C-c), B), C));
        
        if (b <= A-a) q.push(make_pair(make_pair(a+b, 0), c));
        else q.push(make_pair(make_pair(A, b-(A-a)), c));
        
        if (b <= C-c) q.push(make_pair(make_pair(a, 0), b+c));
        else q.push(make_pair(make_pair(a, b-(C-c)), C));
        
        if (c <= A-a) q.push(make_pair(make_pair(a+c, b), 0));
        else q.push(make_pair(make_pair(A, b), c-(A-a)));
        
        if (c <= B-b) q.push(make_pair(make_pair(a, b+c), 0));
        else q.push(make_pair(make_pair(a, B), c-(B-b)));
    }
    
    for (int i = 0; i < k-1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (ret[i] > ret[j]) {
                int tmp = ret[i];
                ret[i] = ret[j];
                ret[j] = tmp;
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    bfs();
    return 0;
}


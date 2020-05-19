#include <bits/stdc++.h>
using namespace std;

long long S;

int main() {
    long long sum = 0, cnt = 0;
    scanf("%lld", &S);
    for (long long i = 1; ; i++) {
        if (sum <= S) {
            sum += i;
            cnt++;
        }
        else break;
    }
    printf("%lld\n", cnt-1);
    return 0;
}


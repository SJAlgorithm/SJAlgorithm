//
//  17212.cpp
//  main
//
//  Created by wi_seong on 2022/02/26.
//

#include <iostream>
#include <algorithm>

using namespace std;
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    d[1] = 1;
    d[2] = 1;
    d[3] = 2;
    d[4] = 2;
    d[5] = 1;
    d[6] = 2;
    d[7] = 1;
    for(int i = 8; i <= n; i++) {
        if (i % 7 == 0) d[i] = i / 7;
        else d[i] = min({ d[i - 7],d[i - 5],d[i - 2],d[i - 1] }) + 1;
    }
    cout << d[n];
    return 0;
}
/*
 1 1 2 2 1
 */

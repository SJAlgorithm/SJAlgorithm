//
//  11568.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/03/13.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = d[0] = 1;
    for(int i = 1; i <= n; i++) {
        d[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j] && d[j] + 1 > d[i])
                d[i] = d[j] + 1;
        }
        res = max(res, d[i]);
    }
    cout << res;
    return 0;
}

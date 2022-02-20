//
//  1577.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>

using namespace std;
int n, m, k;
unsigned long long d[101][101];
bool x[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    while(k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x[b+d][a+c] = 1;
    }
    
    for(int i = 1; i <= m; i++) {
        if(x[2*i-1][0]) break;
        d[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(x[0][2*i-1]) break;
        d[0][i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(!x[2*i-1][2*j]) d[i][j] += d[i-1][j];
            if(!x[2*i][2*j-1]) d[i][j] += d[i][j-1];
        }
    }
    cout << d[m][n];
    
    return 0;
}

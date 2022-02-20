//
//  4095.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int ans;
int d[1001][1001];
int board[1001][1001];

void input() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
            d[i][j] = board[i][j];
            ans = max(ans, d[i][j]);
        }
}

void solve() {
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(board[i][j]) {
                d[i][j] = min(d[i-1][j-1], min(d[i][j-1], d[i-1][j])) + 1;
                ans = max(ans, d[i][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        ans = 0;
        input();
        solve();
        cout << ans << '\n';
    }
    
    return 0;
}

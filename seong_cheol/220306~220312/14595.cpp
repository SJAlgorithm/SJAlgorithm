//
//  14595.cpp
//  main
//
//  Created by wi_seong on 2022/03/13.
//

#include <iostream>

using namespace std;
int n, m;
bool r[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        for(int i = a + 1; i <= b; i++) r[i] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(!r[i]) ans++;
    cout << ans;
    return 0;
}

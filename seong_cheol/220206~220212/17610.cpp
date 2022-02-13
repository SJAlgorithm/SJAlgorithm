//
//  main.cpp
//  17610
//
//  Created by wi_seong on 2022/02/12.
//

#include <iostream>

using namespace std;
bool d[14][260001];
int weight[14];
int n;

void solve(int i, int w) {
    if(i > n || d[i][w]) return;
    d[i][w] = true;
    solve(i + 1, w);
    solve(i + 1, w + weight[i]);
    solve(i + 1, abs(w - weight[i]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }
    
    solve(0,0);
    
    for(int i = 1; i <= sum; i++)
        if(!d[n][i]) ans++;
    cout << ans;
    
    return 0;
}

//
//  5624.cpp
//  main
//
//  Created by wi_seong on 2022/03/14.
//

#include <iostream>

using namespace std;
int n;
int a[5001];
bool vis[400001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(vis[a[i] - a[j] + 200000]) {
                res++;
                break;
            }
        }
        for(int j = 0; j <= i; j++)
            vis[a[i] + a[j] + 200000] = 1;
    }
    cout << res;
    
    return 0;
}

//
//  5052.cpp
//  main
//
//  Created by wi_seong on 2022/03/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n;
vector<pair<int, string>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        bool chk = false;
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            int len = int(s.length());
            v.push_back({len, s});
        }
        for(int i = 0; i < n; i++)
        if(!chk) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}

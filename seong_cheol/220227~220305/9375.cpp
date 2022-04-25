//
//  9375.cpp
//  main
//
//  Created by wi_seong on 2022/03/03.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<string, int> m;
        for(int i = 0; i < n; i++) {
            string name, catag;
            cin >> name >> catag;
            if(m.find(catag) == m.end())  m.insert({catag, 1});
            else m[catag]++;
        }
        int ans = 1;
        for(auto i : m)
            ans *= i.second + 1;
        ans -= 1;
        cout << ans << '\n';
    }
    
    return 0;
}

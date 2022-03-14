//
//  1864.cpp
//  main
//
//  Created by wi_seong on 2022/03/13.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        string s; cin >> s;
        if(s[0] == '#') break;
        int len = int(s.length());
        int ans = 0;
        for(int i = 0; i < len; i++) {
            int n;
            if(s[i] == '-') n = 0;
            else if(s[i] == '\\') n = 1;
            else if(s[i] == '(') n = 2;
            else if(s[i] == '@') n = 3;
            else if(s[i] == '?') n = 4;
            else if(s[i] == '>') n = 5;
            else if(s[i] == '&') n = 6;
            else if(s[i] == '%') n = 7;
            else n = -1;
            ans += n * (1 << 3 * (len - i - 1));
        }
        cout << ans << '\n';
    }
    
    return 0;
}

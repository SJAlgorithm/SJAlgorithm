//
//  19539.cpp
//  main
//
//  Created by wi_seong on 2022/03/14.
//

#include <iostream>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int c2, c3;
    c2 = c3 = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        c2 += a / 2;
        c3 += a;
    }
    if(c3 % 3 != 0) cout << "NO";
    else {
        c3 /= 3;
        if(c2 >= c3) cout << "YES";
        else cout << "NO";
    }
    
    return 0;
}

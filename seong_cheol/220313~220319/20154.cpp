//
//  20154.cpp
//  main
//
//  Created by wi_seong on 2022/03/14.
//

#include <iostream>
#include <string>

using namespace std;
int a[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    int len = int(s.length());
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        cnt += a[s[i] - 'A'];
        cnt %= 10;
    }
    if(cnt%2 == 1) cout << "I'm a winner!";
    else cout << "You're the winner?";
    
    return 0;
}

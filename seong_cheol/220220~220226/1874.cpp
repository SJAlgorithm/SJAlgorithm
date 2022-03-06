//
//  1874.cpp
//  main
//
//  Created by wi_seong on 2022/02/21.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;
string res;
stack<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int cnt = 1;
    while(n--) {
        int x; cin >> x;
        
        while(cnt <= x) {
            s.push(cnt++);
            res += "+\n";
        }
        if(s.top() != x) {
            cout << "NO";
            return 0;
        }
        s.pop();
        res += "-\n";
    }
    cout << res;
    return 0;
}

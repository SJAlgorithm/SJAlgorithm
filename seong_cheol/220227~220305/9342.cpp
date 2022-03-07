//
//  9342.cpp
//  main
//
//  Created by wi_seong on 2022/03/06.
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    regex r(R"(^[A-F]?A+F+C+[A-F]?$)");
    while(t--) {
        string s; cin >> s;
        regex_match(s, r) ? cout << "Infected!" << '\n' : cout << "Good" << '\n';
    }
    
    return 0;
}

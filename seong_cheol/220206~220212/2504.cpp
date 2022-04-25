//
//  main.cpp
//  2504
//
//  Created by wi_seong on 2022/01/28.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    stack<char> st;
    int sum = 0;
    int num = 1;
    
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            num *= 2;
            st.push(s[i]);
        } else if (s[i] == '[') {
            num *= 3;
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i-1] == '(') sum += num;
            st.pop();
            num /= 2;
        }  else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i-1] == '[') sum += num;
            st.pop();
            num /= 3;
        }
    }
    if (st.empty()) cout << sum;
    else cout << 0;
    
    return 0;
}

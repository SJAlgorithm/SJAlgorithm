//
//  11279.cpp
//  main
//
//  Created by wi_seong on 2022/03/14.
//

#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(a);
    }
    
    return 0;
}

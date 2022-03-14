//
//  15664.cpp
//  main
//
//  Created by wi_seong on 2022/02/27.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[10];
int num[10];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i = st; i < n; i++) {
        if(tmp != num[i]) {
            arr[k] = i;
            tmp = num[arr[k]];
            func(k + 1,i + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    func(0, 0);
    
    return 0;
}

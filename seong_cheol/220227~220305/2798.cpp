//
//  2798.cpp
//  main
//
//  Created by wi_seong on 2022/03/06.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[101];
bool isused[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    fill(isused + 3, isused + n, true);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int mx = 0;
    do {
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(!isused[i]) sum += arr[i];
        if(sum <= m) mx = max(mx, sum);
    } while(next_permutation(isused, isused + n));
    cout << mx;
    
    return 0;
}

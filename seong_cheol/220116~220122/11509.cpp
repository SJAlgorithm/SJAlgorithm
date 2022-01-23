//
//  main.cpp
//  11509
//
//  Created by wi_seong on 2022/01/16.
//

#include <iostream>

using namespace std;

int N;
int MX = 1000001;
int ans = 0;

void solution() {
    cin >> N;
    
    int arrow[MX];
    fill(arrow, arrow+MX, 0);
    for(int i = 0; i < N; i++) {
        int M; cin >> M;
        if(arrow[M + 1] == 0) {
            ans++;
            arrow[M]++;
        } else {
            arrow[M+1]--;
            arrow[M]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    solution();
    cout << ans;
    
    return 0;
}

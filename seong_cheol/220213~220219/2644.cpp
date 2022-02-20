//
//  2644.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int a, b;
vector<int> v[101];
int dist[101];

int bfs(int a, int b) {
    queue<int> q;
    q.push(a);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == b) return dist[b];
        for(auto x : v[cur]) {
            if(!dist[x]) {
                q.push(x);
                dist[x] = dist[cur] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> a >> b;
    cin >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << bfs(a, b);
    
    return 0;
}

//
//  14284.cpp
//  main
//
//  Created by wi_seong on 2022/02/20.
//

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int v, e, st, en;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[5001];
int d[5001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    fill(d,d+v+1,INF);
    while(e--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cin >> st >> en;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] < cur.X) continue;
        if(cur.Y == en) {
            cout << cur.X;
            return 0;
        }
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    
    return 0;
}

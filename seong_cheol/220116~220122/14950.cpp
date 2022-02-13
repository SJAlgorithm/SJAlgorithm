//
//  main.cpp
//  14950
//
//  Created by wi_seong on 2022/01/16.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, t;
int ans = 0;

int isVisited[10001];
vector<vector<pair<int, int>>> edges;
priority_queue<pair<int, int>> pq;

void prim(int here, int cnt) {
    
    isVisited[here] = 1;
    
    for(int i = 0; i < edges[here].size(); i++) {
        int next = edges[here][i].first;
        int cost = edges[here][i].second;
        
        if(isVisited[next] == 0) pq.push({-cost, next});
    }
    
    while (!pq.empty()) {
        int next = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(isVisited[next]) continue;
        ans += cost + cnt*t;
        prim(next, cnt + 1);
        return;
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> t;
    edges.resize(N+1);
    
    int a, b, c;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    
    prim(1, 0);
    cout << ans;
    
    return 0;
}

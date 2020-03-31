// "최단거리", https://www.acmicpc.net/problem/1753
// writen in C++
// 2020. 03. 29
// notjustmoney
#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 100000004
using namespace std;
typedef pair<int, int> ii;
struct cmp {
  bool operator()(ii x, ii y) {
    return (x.second > y.second); 
  }
};
vector<vector<ii> > adj(20001);
vector<int> dist(20001);
priority_queue<ii, vector<ii>, cmp> pq;
int main() {
  int V, E, K;
  scanf("%d %d", &V, &E);
  scanf("%d", &K);
  for(int i = 0; i < E; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(make_pair(v, w));
  }

  dist[K] = 0;
  pq.push(make_pair(K, INF));
  for(int i = 1; i <= V; i++) {
    if(i != K) dist[i] = INF;
    pq.push(make_pair(i, INF));
  }

  while(!pq.empty()) {
    int u = pq.top().first; pq.pop();

    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int alt = dist[u] + adj[u][i].second;
      if(alt < dist[v]) {
        dist[v] = alt;
        pq.push(make_pair(v, dist[v]));
      }
    }
  }

  for(int i = 1; i <= V; i++) {
    if(dist[i] == INF) printf("INF\n");
    else printf("%d\n", dist[i]);
  }
  return 0;
}

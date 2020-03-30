// <최단경로> - BOJ_1753
// 다익스트라

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9; // 10억

vector<vector<pii>> adj;
int d[20010];
int V,E,K; // 정점, 간선, 시작정점

void dijkstra(int st){
    priority_queue<pii> pq;
    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = -1 * pq.top().first; // 우선순위큐에서 힙은 큰것부터 나오기때문에 작은값을 뽑기위해 -1을 곱하여 push함
        pq.pop();

        if (d[cur] < dis) continue; // ....

        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].first;
		    int nextDis = dis + adj[cur][i].second;

			if (nextDis < d[next]) {
				d[next] = nextDis;
				pq.push(make_pair(-1*nextDis, next));
			}
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E>>K;
    adj.resize(V+1);

    for(int i=1; i<=E; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    for(int i=1; i<=V; i++){
        d[i] = INF;
    }

    dijkstra(K);

    for(int i=1; i<=V; i++) {
        if(d[i]==INF) cout<<"INF"<<'\n';
        else cout<<d[i]<<'\n';
    }
}
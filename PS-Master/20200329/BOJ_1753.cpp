// <최단경로> - BOJ_1753
// 다익스트라

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9; // 10억

vector<vector<pii>> adj;
vector<int> d;
int V,E,K; // 정점, 간선, 시작정점

void dijkstra(int st){
    priority_queue<pii> pq; // 우선순위 큐를 사용하여 힙트리 자료구조로 
    
    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){
        // 아래 코드 3줄? : pop하여 방문처리
        int cur = pq.top().second;
        int dis = -1 * pq.top().first;
        pq.pop();

        // 아래 if문? : 큐에서 뽑아온 값(dis)이 기존에 저장된 값(d[cur])보다 클때 continue;
        // 즉, 그리디하게 탐색하면서 더 짧은 경로를 발견하여 큐에 들어간 노드가 이전에 먼저 큐에 들어가 있었다면, 
        // 아래 코드를 통해 그 노드에 대한 인접노드탐색을 패스함.
        
        if (dis > d[cur]) {
            cout<<"node num : "<<cur<<",  saved dist in Q: "<<d[cur]<<",  d[num] : "<<dis<<'\n'; // 확인용 출력
            continue;
        }

        // 방문처리된 노드의 인접노드 탐색
        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].first;
		    int nextDis = dis + adj[cur][i].second;

			if (nextDis < d[next]) { // 최단거리 업데이트, 거리 업데이트된 정보 큐에 다시 삽입. 
				d[next] = nextDis;
				pq.push(make_pair(-1*nextDis, next)); //해당노드(next)는 큐에 중복으로 삽입됨. 저장된 거리는 다름 -> 위의 if문에서 중복노드 걸러줌
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
    d.resize(V+1,INF);
    dijkstra(K);

    for(int i=1; i<=V; i++) {
        if(d[i]==INF) cout<<"INF"<<'\n';
        else cout<<d[i]<<'\n';
    }
}
// 네트워크 플로우
// 에드몬드 카프(Edmonds-Karp) 알고리즘 : brute force
// TC: O(VE^2)
// https://gseok.gitbooks.io/algorithm/content/b124-d2b8-c6cc-d06c-d50c-b85c-c6b0/d3ec-b4dc-d480-cee4-c2a828-ford-fulkerson-c560-b4dc-baac-b4dc-ce74-d50428-edmonds-karp.html

#include<bits/stdc++.h>
#define MAX_N 52
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
// flo: flow, cap: capacity
int flo[MAX_N][MAX_N]{}, cap[MAX_N][MAX_N]{}; 
vector<int> adj[MAX_N]{};

// 에드몬드 카프 Algorithm
// st: Source, ed: Sink
int networkFlow(int st, int ed){ 
    int totalFlow = 0;

    while(1){ // 증가경로(augmenting path) BFS로 찾기
        int viPrev[MAX_N]; // BFS 경로 역추적
        memset(viPrev, 0x3f, sizeof(viPrev)); // 방문하지 않았으면 INF처리

        queue<int> q;
        q.push(st);
        viPrev[st] = -1; // st 방문처리

        while(!q.empty()){
            int cn = q.front();
            q.pop();
            if(cn == ed) break; // sink도착 즉, 증가 경로를 찾았다면 BFS break

            for(int i=0; i<adj[cn].size(); i++){
                int nn = adj[cn][i];
                if(viPrev[nn]!=INF) continue; // 방문체크
                // 흘러보낼 flow가 더이상 없으면 next node
                if(cap[cn][nn] - flo[cn][nn] <= 0) continue;
                q.push(nn);
                viPrev[nn] = cn;
            }
        }

        //BFS에서 증가경로를 발견하지 못했으면 경로찾기 종료
        if(viPrev[ed]==INF) break;

        // 증가경로 역추적하여 해당경로에서 min flow 찾기
        // bfs에서 queue에 push할때마다 pair로 저장하여 min update해도 됨
        int flow = INF;
        for (int i = ed; i != st; i = viPrev[i]){
            flow = min(flow, cap[viPrev[i]][i] - flo[viPrev[i]][i]);
        }
        
        // 증가경로에 해당하는 노드들 min flow 더해줌, 역방향은 빼줌
        for (int i = ed; i != st; i = viPrev[i]) {
            flo[viPrev[i]][i] += flow;
            flo[i][viPrev[i]] -= flow;
        }

        // 모든 증가경로의 min flow를 더하면 최대유량이므로
        // 또는 Sink(ed)노드와 연결된 노드와의 flow를 모두 더해도 됨
        totalFlow += flow;
    }

    return totalFlow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    char x,y;
    int a,b,k;
    for(int i=0; i<N; i++){
        cin>>x>>y>>k;
        if(x==y) continue; // self 경로 예외처리
        // 역방향 데이터가 실제로 존재하는 경우의 예외처리는 되어있지 않음
        
        if(x>='a' && x<='z') a = x-'a'+26;
        else a = x-'A';
        if(y>='a' && y<='z') b = y-'a'+26;
        else b = y-'A';
        
        adj[a].push_back(b); // 
        adj[b].push_back(a); // 허수값(-)을 가진 역방향 간선을 위한 간선추가
        cap[a][b] += k; // 같은방향의 간선(중복간선) +로 처리
        cap[b][a] += k; // 허수값을 가진 역방향간선도 마찬가지
    }
    
    cout<<networkFlow(0,'Z'-'A');
    return 0;
}
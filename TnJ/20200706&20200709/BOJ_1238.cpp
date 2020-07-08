// <파티> - BOJ_1238
// 다익스트라. 역방향 이용한 빠른 풀이.
// max_ = max(d[i][x] + d[x][i], max_); 가 아닌
// max_ = max(d1[i] + d2[i]);
// (i->X)까지 거리, (X->i)거리를 구해야 한다면, (i->X)에 대한 adj를 역방향으로 따로 저장하여 
// d1[X->i] + d2[X-i] 과 같은 방법으로 빠르게 구할 수 있음. (원래는 i(0...N)에서 X까지의 모든 경로를 구해야 함)

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define ini(x, y) memset(x, y, sizeof(x))
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL)
#define xx first
#define yy second
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int N,M,X;
vector<pii> adj1[1001];
vector<pii> adj2[1001];
int d1[1001]{};
int d2[1001]{};

void solve(int *d, vector<pii> *adj){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii(0,X));
    d[X] = 0;

    while(!pq.empty()){
        int cd = pq.top().xx;
        int cp = pq.top().yy;
        pq.pop();

        if(d[cp] < cd) continue;

        for(int i=0; i<adj[cp].size(); i++){
            int nd = adj[cp][i].yy + cd;
            int np = adj[cp][i].xx;

            if(nd < d[np]){
                d[np] = nd;
                pq.push(pii(nd,np));
            }
        }
    }
}

int main() {
    FASTIO;
    cin>>N>>M>>X;
    ini(d1,0x3f);
    ini(d2,0x3f);
    
    int a,b,c;
    while(M--){
        cin>>a>>b>>c;
        adj1[a].push_back({b,c});
        adj2[b].push_back({a,c}); // 역방향
    }

    for(int i=1; i<=N; i++){
        solve(d1,adj1);
        solve(d2,adj2);
    }

    int max_=0;
    for(int i=1; i<=N; i++){
        max_ = max(d1[i] + d2[i], max_);
    }

    cout<<max_;
}
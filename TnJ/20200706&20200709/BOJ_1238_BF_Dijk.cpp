// <파티> - BOJ_1238
// 다익스트라 풀이. (전체경로 구한 풀이 Brute Force)

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
vector<pii> adj[1001];
int d[1001][1001]{};

void solve(int st){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii(0,st));
    d[st][st] = 0;

    while(!pq.empty()){
        int cd = pq.top().xx;
        int cp = pq.top().yy;
        pq.pop();

        if(d[st][cp] < cd) continue;

        for(int i=0; i<adj[cp].size(); i++){
            int nd = adj[cp][i].yy + cd;
            int np = adj[cp][i].xx;

            if(nd < d[st][np]){
                d[st][np] = nd;
                pq.push(pii(nd,np));
            }
        }
    }
}

int main() {
    FASTIO;
    cin>>N>>M>>X;
    int a,b,c;
    ini(d,0x3f);
    for(int i=1; i<=M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    for(int i=1; i<=N; i++){
        solve(i);
        solve(X);
    }

    int max_=0;
    for(int i=1; i<=N; i++){
        max_ = max(d[i][X] + d[X][i], max_);
    }

    cout<<max_;
}
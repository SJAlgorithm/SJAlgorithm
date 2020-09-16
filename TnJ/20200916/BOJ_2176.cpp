// <합리적인 이동경로> BOJ_2176
// 다익스트라, DP

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = INT32_MAX;

int N,M;
vector<pii> adj[1001]{};
int d[1001]{};
int dp[1001]{};

void solve(int stt) {
    priority_queue<pii> pq;
    pq.push({0,stt});
    d[stt] = 0;
    dp[stt] = 1;

    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cp = pq.top().yy;
        pq.pop();

        if(cd>d[cp]) continue;
        for(int i=0; i<adj[cp].size(); i++){
            int np = adj[cp][i].xx;
            int nd = adj[cp][i].yy + cd;

            if(nd < d[np]){
                d[np] = nd;
                pq.push({-nd, np});
            }
            if (d[np] < cd) dp[cp] += dp[np];

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int j=0; j<=N; j++) d[j] = INF;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    solve(2);
    cout<<dp[1];
}
#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int T,N,D,C;
vector<vector<pii>> adj;
int d[10001]{};

void solve(){
    queue<pii> pq;
    pq.push({0,C}); // dis, cpos
    d[C] = 0;

    while(!pq.empty()){
        int cd = pq.front().xx;
        int cp = pq.front().yy;
        pq.pop();
        
        if(cd>d[cp]) continue;

        for(int i=0; i<adj[cp].size(); i++){
            int nd = cd + adj[cp][i].yy;
            int np = adj[cp][i].xx;
            if(nd < d[np]){
                d[np] = nd;
                pq.push({nd,np});
            }
        }
    }

    int cnt=0, max_=0;
    for(int i=1; i<=N; i++) {
        if(d[i]!=INF) {
            cnt++;
            max_ = max(max_, d[i]);
        }
    }
    cout<<cnt<<' '<<max_<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>D>>C;
        memset(d,0x3f,sizeof(d));
        adj.clear();
        adj.resize(N+1);
        int a,b,s;
        for(int i=0; i<D; i++){
            cin>>a>>b>>s;
            adj[b].push_back({a,s});
        }
        solve();
    }
}
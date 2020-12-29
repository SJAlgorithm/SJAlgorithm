// <MooTube (Silver)> - BOJ_15591
// DFS버전

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;

int N,Q,k,v;
int cnt=0;
vector<vector<pii>> g;
bool vi[5001] = {false,};

void dfs(int s, int curMU) {
    int t = curMU;
    vi[s] = true;
    for(auto val : g[s]) {
        curMU = t;
        if(!vi[val.first]) {
            curMU = min(curMU,val.second);
            if(curMU >= k) {
                cnt++;
                dfs(val.first,curMU);
            }
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    g.resize(N+1);
    for(int i=1; i<N; i++){
        int p,q,r;
        cin>>p>>q>>r;
        g[p].push_back({q,r});
        g[q].push_back({p,r});
    }
    
    while(Q--){
        cin>>k>>v;
        cnt = 0;
        memset(vi,false,sizeof(vi));
        dfs(v,INF);
        cout<<cnt<<'\n';
    }

}
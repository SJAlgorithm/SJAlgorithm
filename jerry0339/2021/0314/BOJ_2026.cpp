// DFS, 백트래킹

#include<bits/stdc++.h>
using namespace std;

int K,N,F;
int deg[901]{};
bool adj[901][901]{};
bool vi[901]{};
vector<int> v;

bool dfs(int dpt, int now, vector<int> &t){
    if(dpt==K) return true;
    for(int i=now; i<=N; i++){
        if(vi[i]) continue;
        bool chk = true;
        for(auto val : t){
            if(adj[val][i]) continue;
            chk = false;
            break;
        }
        if(chk) {
            t.push_back(i);
            if(dfs(dpt+1, i+1, t)) return true;
            else t.pop_back();
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K>>N>>F;
    int a,b;
    while(F--){
        cin>>a>>b;
        adj[a][b] = true;
        adj[b][a] = true;
        deg[a]++;
        deg[b]++;
    }

    for(int i=1; i<=N; i++)
        if(deg[i]<K-1) 
            vi[i] = true;

    if(!dfs(0,1,v)) {
        cout<<-1<<'\n';
        return 0;
    }
    for(auto val : v){
        cout<<val<<'\n';
    }
}
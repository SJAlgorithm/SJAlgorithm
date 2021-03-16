#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX_N 100000
using namespace std;
typedef pair<int,int> pii;

int N,M,st,ed;
vector<pii> adj[MAX_N+1]{};
bool vi[MAX_N+1]{};

bool isP(int mid){
    memset(vi,0,sizeof(vi));
    queue<int> q;
    q.push(st);
    vi[st] = true;

    while(!q.empty()){
        int cn = q.front();
        q.pop();
        
        if(cn==ed) return true;
        for(auto next : adj[cn]){
            if(vi[next.xx] || next.yy<mid) continue;
            q.push(next.xx);
            vi[next.xx] = true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    int minE=1e9, maxE=1;
    while(M--){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        minE = min(minE, c);
        maxE = max(maxE, c);
    }
    cin>>st>>ed;

    int s=minE, e=maxE;
    while(s<=e){
        int mid = (s+e)/2;
        if(isP(mid)) s = mid + 1;
        else e = mid - 1;
    }

    cout<<e;
}
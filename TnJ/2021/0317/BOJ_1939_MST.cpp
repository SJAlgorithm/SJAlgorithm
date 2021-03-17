// BOJ_1939
// 크루스칼 MST 이용

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX_N 10000
using namespace std;
typedef pair<int,int> pii;

struct info{
    int c,a,b;
};

int N,M,st,ed;
vector<info> edge;
vector<pii> adj[MAX_N+1]{};
int par[MAX_N+1]{};
bool vi[MAX_N+1]{};

int find(int k) {
    if (k == par[k]) return k;
    else return par[k] = find(par[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    par[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) par[i] = i;

    int a,b,c;
    while(M--){
        cin>>a>>b>>c;
        edge.push_back({c,a,b});
    }
    cin>>st>>ed;
    sort(edge.begin(), edge.end(), [&](info a, info b) -> bool{
        return a.c > b.c;
    });

    int cnt = 0;
    for(auto e : edge){
        int k = e.c;
        int x = e.a;
        int y = e.b;
        if(find(x)==find(y)) continue;
        merge(x,y);
        adj[x].push_back({y,k});
        adj[y].push_back({x,k});
        cnt++;
        if(cnt==N-1) break;
    }

    queue<pii> q;
    q.push({st,1e9});
    vi[st] = true;

    while(!q.empty()){
        int cn = q.front().xx;
        int minE = q.front().yy;
        q.pop();
        if(cn==ed) {
            cout<<minE;
            return 0;
        }
        for(auto next : adj[cn]){
            if(vi[next.xx]) continue;
            q.push({next.xx, min(minE, next.yy)});
            vi[next.xx] = true;
        }
    }
}
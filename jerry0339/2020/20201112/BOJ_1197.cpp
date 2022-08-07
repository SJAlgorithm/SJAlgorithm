// <최소 스패닝 트리> - BOJ_1197
// MST: 최소 신장 트리 -> Prim알고리즘 이용

#include <bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x))
#define rall(v) (v).rbegin(), (v).rend()
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int V,E;
vector<pii> adj[10010]{};
int vi[10010]{};

int main() {
    
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>V>>E;
    int a,b,c;
    for(int i=0; i<E; i++) {
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
	
    ll ans =0;
    priority_queue<pii> pq;
    pq.push({0,1});

    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cn = pq.top().yy;
        pq.pop();
        if(vi[cn]) continue;
        ans += cd;
        for(int i=0; i<adj[cn].size(); i++){
            pq.push({-adj[cn][i].yy, adj[cn][i].xx});
        }
        vi[cn] = true;
    }

    cout<<ans;
}
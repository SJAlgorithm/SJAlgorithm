#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define xx first
#define yy second
#define MAX_N 100000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll N, M, maxPower = (ll)floor(log2(MAX_N));
ll ac[MAX_N+1][21]{};
ll dist[MAX_N+1]{};
ll dpt[MAX_N+1]{};
vector<pll> adj[MAX_N+1]{};

void dfs(ll now, ll parent, ll nd) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;
    dist[now] = nd;

    for (ll i = 1; i <= maxPower; i++)
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (auto next : adj[now]) {
        if (next.xx == parent) continue;
        dfs(next.xx, now, nd + next.yy);
    }
}

ll lca(ll x, ll y) {
    if (dpt[x] > dpt[y]) swap(x, y);
    for (ll i = maxPower; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)) 
            y = ac[y][i];
    }
    if (x == y)return x; 
    for (ll i = maxPower; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    return ac[x][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    ll x,y,c;
    for (ll i = 0; i < N-1; i++) {
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1, 0, 0);

    cin>>M;
    ll u,k;
    while (M--) {
        cin>>u>>x>>y;
        if(u==1){
            ll common = lca(x, y);
            cout<<dist[x] + dist[y] - dist[common]*2<<'\n';
        } else { // u==2
            cin>>k;
            ll lcaN = lca(x, y);
            ll next;
            if (dpt[x]-dpt[lcaN]+1 >= k) next=x, k--;
            else {
                next=y;
                k = (dpt[y]+dpt[x] - dpt[lcaN]*2) - k + 1;
            }
            for (int i = maxPower; i >= 0; i--) {
                if ((1LL << i) <= k) {
                    k -= (1 << i);
                    next = ac[next][i];
                }
            }
            cout<<next<<'\n';
        }
    }

}
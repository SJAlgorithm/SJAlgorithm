#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define xx first
#define yy second
#define MAX_N 100000
using namespace std;
typedef pair<int,int> pii;

int N, M, maxPower = (int)floor(log2(MAX_N));
int ac[MAX_N+1][21]{};
int minE[MAX_N+1][21]{};
int maxE[MAX_N+1][21]{};
int dpt[MAX_N+1]{};
vector<pii> adj[MAX_N+1]{};

void dfs(int now, int parent) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;

    for (int i = 1; i <= maxPower; i++){
        ac[now][i] = ac[ac[now][i-1]][i-1];
        minE[now][i] = min(minE[now][i-1] , minE[ac[now][i-1]][i-1]);
        maxE[now][i] = max(maxE[now][i-1] , maxE[ac[now][i-1]][i-1]);
    }

    for (auto next : adj[now]) {
        if (next.xx == parent) continue;
        minE[next.xx][0] = next.yy;
        maxE[next.xx][0] = next.yy;
        dfs(next.xx, now);
    }
}

pii lca(int x, int y) {
    int minRes = 1000000;
    int maxRes = 1;
    if (dpt[x] > dpt[y]) swap(x, y);
    for (int i = maxPower; i >= 0; i--) {
        if (dpt[y] - dpt[x] >= (1 << i)){
            minRes = min(minRes, minE[y][i]);
            maxRes = max(maxRes, maxE[y][i]);
            y = ac[y][i];
        }
    }
    if (x == y) return pii(minRes,maxRes);
    for (int i = maxPower; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            minRes = min({minRes, minE[x][i], minE[y][i]});
            maxRes = max({maxRes, maxE[x][i], maxE[y][i]});
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    minRes = min({minRes, minE[x][0], minE[y][0]});
    maxRes = max({maxRes, maxE[x][0], maxE[y][0]});
    // int lcaN = ac[x][0];
    return pii(minRes, maxRes);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    int x,y,c;
    for (int i = 0; i < N-1; i++) {
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1, 0);

    cin>>M;
    while (M--) {
        cin>>x>>y;
        pii ans = lca(x, y);
        cout<<ans.xx<<' '<<ans.yy<<'\n';
    }

}
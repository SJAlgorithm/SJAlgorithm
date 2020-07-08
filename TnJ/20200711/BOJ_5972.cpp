// <택배 배송> - BOJ_5972
// 다익스트라

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

int N,M;
vector<pii> adj[50001];
int d[50001]{};

void solve(int st){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii(0,st));
    d[st] = 0;

    while(!pq.empty()){
        int cd = pq.top().xx;
        int cp = pq.top().yy;
        pq.pop();

        if(d[cp] < cd) continue;

        for(int i=0; i<adj[cp].size(); i++){
            int np = adj[cp][i].xx;
            int nd = adj[cp][i].yy + cd;

            if(nd < d[np]){
                d[np] = nd;
                pq.push(pii(nd,np));
            }
        }
    }
}

int main() {
    FASTIO;
    cin>>N>>M;
    int a,b,c;
    ini(d,0x3f);
    while(M--){
        cin>>a>>b>>c;
        adj[a].push_back(pii(b,c));
        adj[b].push_back(pii(a,c));
    }

    solve(1);
    cout<<d[N];
}
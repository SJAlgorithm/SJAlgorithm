// <적의 적> - BOJ_12893
// bfs풀이

#include<bits/stdc++.h>
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
typedef pair<pii,pii> piiii;
typedef vector<pii> vecpii;
typedef vector<int> veci;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;

int N,M;
vector<int> adj[2010]{};
bool vi[2][2010]{};

bool solve(int st){
    queue<pii> q;
    q.push({0,st});
    vi[0][st] = true;

    while(!q.empty()){
        int cd = q.front().xx;
        int cp = q.front().yy;
        q.pop();

        for(int i=0; i<adj[cp].size(); i++){
            int np = adj[cp][i];
            int nd = !cd;
            if(vi[nd][np]) continue;
            if(vi[cd][np]) return false;
            q.push({nd,np});
            vi[nd][np] = true;
        }
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    while(M--){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(b);
    }

    for(int i=1; i<=N; i++){
        if(!vi[0][i] && !vi[1][i]){
            if(!solve(i)) {
                cout<<0;
                return 0;
            }
        }
    }
	cout<<1;
}
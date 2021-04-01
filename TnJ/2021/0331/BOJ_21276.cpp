#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<memory.h>
#include<math.h>
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
typedef vector<pii> vecpii;
typedef vector<int> veci;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;

vector<int> adj[1002]{};
vector<int> res[1002]{};
vector<string> name;
map<string,int> m;
int parent[1002]{};
int deg[1002]{};

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int N,M;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N;
    string s1, s2;
    for(int i=0; i<N; i++) parent[i] = i;
    
    for(int i=1; i<=N; i++) {
        cin>>s1;
        name.push_back(s1);
    }
    sort(all(name));
    for(int i=0; i<N; i++) m[name[i]] = i;

    cin>>M;
    while(M--){
        cin>>s1>>s2;
        int x = m[s1], y = m[s2];
        merge(x, y);
        adj[y].push_back(x);
        deg[x]++;
    }

    set<int> chk;
    vector<int> nd;
    for(int i=0; i<N; i++){
        chk.insert(find(i));
        if(!deg[i]) nd.push_back(i);
    }
    
    cout<<chk.size()<<'\n';
    for(auto val : nd) cout<<name[val]<<' ';
    cout<<'\n';
    for(int i=0; i<N; i++){
        nd.clear();
        int cdeg = deg[i];
        sort(all(adj[i]));
        for(auto val : adj[i]){
            if(cdeg+1 == deg[val]) nd.push_back(val);
        }
        cout<<name[i]<<' '<<nd.size()<<' ';
        for(auto val : nd) cout<<name[val]<<' ';
        cout<<'\n';
    }
}
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

struct Info{
    ll d,n,s;
    Info(ll d_=0, ll n_=0, ll s_=0) :d(d_), n(n_), s(s_){}
};
struct comp{
    bool operator()(Info &a, Info &b){
        return a.d > b.d;
    }
};

ll N,M,T;
vector<pll> adj[4001]{};
ll dist1[4001]{};
ll dist2[4001][2]{};

void dijk1(){
    priority_queue<Info, vector<Info>, comp> pq;
    pq.push({0,1,-1});
    dist1[1] = 0;

    while(!pq.empty()){
        ll cd = pq.top().d;
        ll cn = pq.top().n;
        pq.pop();

        if(dist1[cn] < cd) continue;
        for(auto next : adj[cn]){
            ll nn = next.xx;
            ll nd = next.yy + cd;
            if(dist1[nn] > nd){
                dist1[nn] = nd;
                pq.push({nd,nn,-1});
            }
        }
    }
}

void dijk2(){
    priority_queue<Info, vector<Info>, comp> pq;
    pq.push({0,1,0});
    dist2[1][0] = 0;

    while(!pq.empty()){
        ll cd = pq.top().d;
        ll cn = pq.top().n;
        ll cs = pq.top().s;
        pq.pop();

        if(dist2[cn][cs] < cd) continue;
        for(auto next : adj[cn]){
            ll nn = next.xx;
            ll ns = !cs;
            ll nd = next.yy;
            if(ns) nd /= 2;
            else nd *= 2;
            nd += cd;
            if(dist2[nn][ns] > nd){
                dist2[nn][ns] = nd;
                pq.push({nd,nn,ns});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    
    for(int i=1; i<=N; i++) {
        dist1[i] = llINF;
        dist2[i][0] = llINF;
        dist2[i][1] = llINF;
    }

    ll a,b,c;
    while(M--) {
        cin>>a>>b>>c;
        adj[a].push_back({b,c*2LL});
        adj[b].push_back({a,c*2LL});
    }
    
    dijk1();
    dijk2();

    ll sum = 0;
    for(ll i=1; i<=N; i++)
        if(dist1[i] < min(dist2[i][0],dist2[i][1])) sum++;
    
    cout<<sum;
}
#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX 100000
#define MAX_N 100001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF = 1000001LL;

ll arr[MAX_N]{};
ll mint[MAX<<2]{};
ll tree[MAX<<2]{};
ll N,Q;

pll init(ll n, ll s, ll e){
    if(s==e) {
        mint[n] = s;
        tree[n] = arr[s];
        return pll(arr[s], s);
    }
    ll mid = (s+e)>>1;
    pll a = init(n<<1, s, mid);
    pll b = init(n<<1|1, mid+1, e);
    tree[n] = a.xx+b.xx;
    if(arr[a.yy] > arr[b.yy]) {
        mint[n] = b.yy;
        return pll(a.xx+b.xx, b.yy);
    }
    else {
        mint[n] = a.yy;
        return pll(a.xx+b.xx, a.yy);
    }
}

pll query(ll n, ll s, ll e, ll l, ll r){
    if(l>e || r<s) return pll(0, 0);
    if(l<=s && e<=r) return pll(tree[n], mint[n]);
    ll mid = (s+e)>>1;
    pll a = query(n<<1, s, mid, l, r);
    pll b = query(n<<1|1, mid+1, e, l, r);
    if(arr[a.yy] > arr[b.yy]) return pll(a.xx+b.xx, b.yy);
    else return pll(a.xx+b.xx, a.yy);
}

ll solve(ll l, ll r) {
	if (l > r) return 0;
    pll t = query(1, 1, N, l, r);
	ll ans = t.xx * arr[t.yy];
	ans = max(ans, solve(l, t.yy - 1));
	ans = max(ans, solve(t.yy + 1, r));
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    arr[0] = INF;
    cin>>N;
    for(ll i=1; i<=N; i++){
        cin>>arr[i];
    }
    init(1,1,N);

    cout<<solve(1,N)<<'\n';
    
    return 0;
}
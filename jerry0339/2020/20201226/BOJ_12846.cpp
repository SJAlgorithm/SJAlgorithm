// [BOJ 12846] 무서운 아르바이트

#include<bits/stdc++.h>
#define MAX 100000
#define MAX_N 100001
using namespace std;
typedef long long ll;
const ll INF = 1e10;

ll N,M,Q;
ll arr[MAX_N], tree[MAX*4];

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = s;
    ll mid = (s+e)>>1;
    ll a = init(n<<1, s, mid);
    ll b = init(n<<1|1, mid+1, e);
    if(arr[a] > arr[b]) return tree[n] = b;
    else return tree[n] = a;
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(s>r || e<l) return 0;
    if(l<=s && r>=e) return tree[n];
    ll mid = (s+e)>>1;
    ll a = query(n<<1, s, mid, l, r);
    ll b = query(n<<1|1, mid+1, e, l, r);
    if(arr[a] > arr[b]) return b;
    else return a;
}

ll solve(ll l, ll r){
    //if(l==r) return arr[l];
    if (l > r) return 0;
    ll midx = query(1, 1, N, l, r);
    ll ans = (r-l+1) * arr[midx];
    ans = max(ans,solve(l, midx-1));
    ans = max(ans,solve(midx+1, r));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    arr[0] = INF;
    for(ll i=1; i<=N; i++){
        cin>>arr[i];
    }
    init(1,1,N);

    cout<<solve(1,N)<<'\n';
}
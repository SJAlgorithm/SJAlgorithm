// <구간 곱 구하기> - BOJ_11505
// 세그먼트 트리

#include<bits/stdc++.h>
#define MAX 1000000
#define MAX_N 1000000
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll arr[MAX_N]{};
ll tree[MAX<<2]{};
ll N,M,K;

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    return tree[n] = (init(n<<1, s, mid) * init(n<<1|1, mid+1, e))%MOD;
}

ll modify(ll n, ll s, ll e, ll idx, ll val){
    if(idx<s || idx>e) return tree[n];
    if(s==e) return tree[n] = val;
    ll mid = (s+e)>>1;
    return tree[n] = (modify(n<<1, s, mid, idx, val) * modify(n<<1|1, mid+1, e, idx, val))%MOD;
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(l>e || r<s) return 1;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    return (query(n<<1, s, mid, l, r) * query(n<<1|1, mid+1, e, l, r))%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(ll i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int i=0; i<MAX*4; i++) tree[i] = 1;
    init(1,0,N-1);

    M+=K;
    ll a,b,c;
    while(M--){
        cin>>a>>b>>c;
        if(a==2 && b>c) swap(b,c);
        if(a==1){ // b->c
            arr[b-1] = c;
            modify(1, 0, N-1, b-1, c);
        } else { // b~c
            cout<<query(1, 0, N-1, b-1, c-1)<<'\n';
        }
    }

    return 0;
}
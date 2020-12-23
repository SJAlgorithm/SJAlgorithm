// <중앙값 측정> - BOJ_9426
// 세그먼트 트리, 역추적(query)

#include<bits/stdc++.h>
#define MAX_N 65536
using namespace std;
typedef long long ll;

ll arr[250001]{}, tree[MAX_N<<2]{};
ll N,M;

void modify(ll n, ll s, ll e, ll idx, ll diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    ll mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

ll query(ll n, ll s, ll e, ll val){
    if(s==e) return s;
    ll mid = (s+e)>>1;
    if(val<=tree[n<<1]) return query(n<<1, s, mid, val);
    return query(n<<1|1, mid+1, e, val-tree[n<<1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    for(ll i=0; i<N; i++){
        cin>>arr[i];
    }
    ll ans = 0;
    for(ll i=0; i<M; i++) modify(1,0,MAX_N,arr[i],1);
    for(ll i=M; i<N; i++) {
        ans += query(1,0,MAX_N,(M+1)/2);
        modify(1,0,MAX_N,arr[i],1);
        modify(1,0,MAX_N,arr[i-M],-1);
    }
    ans += query(1,0,MAX_N,(M+1)/2);
    cout<<ans;
    return 0;
}
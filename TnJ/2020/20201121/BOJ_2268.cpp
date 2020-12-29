// <수들의 합> - BOJ_2268
// 세그먼트 트리 (비재귀)

#include<bits/stdc++.h>
#define MAX_N 1000001
using namespace std;
typedef long long ll;

ll N,M;
ll t[MAX_N * 2]{};

void init() { // = build()
    for (ll i = N-1; i > 0; --i){
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
}

ll query(ll l, ll r) { // [l, r)
    ll ans = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}

void update(ll pos, ll val) {
    t[pos + N] = val;
    for (pos += N; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll a,b,c;
    while(M--){
        cin>>a>>b>>c;
        if(b>c){
            ll t=b;
            b = c;
            c = t; 
        }
        if(a){
            update(b-1,c);
        } else {
            if(b>c) swap(b,c);
            cout<<query(b-1,c)<<'\n';
        }
    }
}
// <커피숍 2> - BOJ_1275
// 세그먼트 트리 (비재귀)

#include<bits/stdc++.h>
#define MAX_N 100001
using namespace std;
typedef long long ll;

ll N,Q;
ll t[MAX_N * 2];

void init() {
    for (ll i = N-1; i > 0; --i){
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
}

// input l은 0부터
ll query(ll l, ll r) { // [l, r)
    ll ans = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}

// input pos는 0부터
void update(ll pos, ll val) {
    t[pos + N] = val;
    for (pos += N; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for (ll i = 0; i < N; ++i) {
        cin>>t[N + i]; // a[0] => a[n]
    }
    init();
    ll x,y,a,b;
    while(Q--){
        cin>>x>>y>>a>>b;
        // query(sum)함수 실행시에만 조건:x<y 고려
        if(x>y) {
            ll t = x;
            x = y;
            y = t;
        }
        cout<<query(x-1,y)<<'\n';
        update(a-1,b);
    }
}
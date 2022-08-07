#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll M,N,L;
vector<ll> v;
vector<pll> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>L; // 사대, 동물, 사정거리

    ll a,b;
    for(ll i=0; i<M; i++) {
        cin>>a;
        v.push_back(a);
    }
    for(ll i=0; i<N; i++) {
        cin>>a>>b;
        m.push_back({a,b});
    }
    sort(v.begin(), v.end());
    sort(m.begin(), m.end());

    int ans=0;
    for(ll i=0; i<N; i++){
        ll val = L - m[i].yy;
        ll l = lower_bound(v.begin(), v.end(), m[i].xx-val) - v.begin();
        ll r = upper_bound(v.begin(), v.end(), m[i].xx+val) - v.begin();
        if(l<r) ans++;
    }

    cout<<ans;
}
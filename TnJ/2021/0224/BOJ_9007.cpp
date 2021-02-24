#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K,N;
ll t1[1002]{}, t2[1002]{};
vector<ll> v1, v2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;

    while(T--){
        v1.clear();
        v2.clear();
        cin>>K>>N;
        for(ll i=0; i<N; i++) cin>>t1[i];
        for(ll i=0; i<N; i++) cin>>t2[i];
        for(ll i=0; i<N; i++) {
            for(ll j=0; j<N; j++){
                v1.push_back(t1[i]+t2[j]);
            }
        }
        for(ll i=0; i<N; i++) cin>>t1[i];
        for(ll i=0; i<N; i++) cin>>t2[i];
        for(ll i=0; i<N; i++) {
            for(ll j=0; j<N; j++){
                v2.push_back(t1[i]+t2[j]);
            }
        }
        if(N==1) {cout<<v1[0]+v2[0]<<'\n'; continue;}
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        ll ans=v1[0]+v2[0], l, r, tmp;
        for(ll i=0; i<N*N; i++) {
            ll val = K - v1[i];
            ll lb = lower_bound(v2.begin(), v2.end(), val) - v2.begin();
            if(lb==0) lb++;
            if(lb==N*N) lb--;
            if(v2[lb] == val) {ans = K; break;}
            l = abs(val - v2[lb-1]);
            r = abs(val - v2[lb]);
            tmp = abs(K-ans);
            if(l<=r) {
                if(l < tmp) ans = v1[i] + v2[lb-1];
                else if(l == tmp) ans = min(ans, v1[i] + v2[lb-1]);
            } else {
                if(r < tmp) ans = v1[i] + v2[lb];
                else if(r == tmp) ans = min(ans, v1[i] + v2[lb]);
            }
        }

        cout<<ans<<'\n';
    }   
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
struct info{
    ll a,b,c;
};
vector<info> m;

ll isP(ll mid){
    ll a,b,c, res=0;
    for(ll i=0; i<N; i++){
        if(m[i].a > mid) continue;
        a = m[i].a;
        b = m[i].b;
        c = m[i].c;
        b = min(b, mid);
        ll t = (b-a)/c; 
        res += (t+1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    ll a,b,c, max_=0, min_=INT32_MAX;
    for(ll i=0; i<N; i++) {
        cin>>a>>b>>c;
        m.push_back({a,b,c});
        ll t = (b-a)/c;
        t = a+(c*t);
        max_ = max(max_, t);
        min_ = min(min_, a);
    }

    if(isP(max_)%2==0) {
        cout<<"NOTHING";
        return 0;
    }
    
    ll s=min_, e=max_;
    while(s<=e){
        ll mid = (s+e)/2;        
        if(isP(mid)%2) e = mid - 1;
        else s = mid + 1;
    }
    
    cout<<s<<' '<<isP(s)-isP(s-1);
}

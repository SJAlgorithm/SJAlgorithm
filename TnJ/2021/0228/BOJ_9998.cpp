// 삼분탐색(ternary_search) 이용

#include<iostream>
#include<algorithm>
#include<vector>
using namespace::std;
typedef long long ll;

ll N;
ll m1[300010];
ll m2[300010];
 
ll calSum(ll mid){
    ll sum=0, t;
    for(ll i=0; i<N; i++) {
        if(i <= N/2) t = mid + N/2 - i;
        else t = mid + i - N/2;
        sum += abs(m1[i] - t);
        sum += abs(m2[i] - t);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll max_=0;
    for(int i=0; i<N; i++) {
        cin>>m1[i];
        max_ = max(max_, m1[i]);
    }
    for(int i=0; i<N; i++) {
        cin>>m2[i];
        max_ = max(max_, m2[i]);
    }

    ll l = 0, r = max_;
    while(r-l>=3) {
        ll range = (r-l)/3;
        ll mid1 = l + range;
        ll mid2 = r - range;

        ll x = calSum(mid1);
        ll y = calSum(mid2);

        if(x < y) r = mid2;
        else l = mid1;
    }

    ll res = calSum(l), t;
    for(ll i=l+1; i<r; i++){
        t = calSum(i);
        res = min(res, t);
    }
    cout<<res;
}

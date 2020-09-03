// <세 용액> - BOJ_2473
// N^2 풀이 ( 탐색(N)*투포인터(N) )

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define abs(x) ((x) < 0 ? (-(x)) : (x))
typedef long long ll;

ll m[100010]{};
ll N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=0; i<N; i++) cin>>m[i];
    sort(m,m+N);
    
    ll a, b, c;
    ll min_= 3000000001;
    for(ll i=0; i<N; i++){
        ll l=0, r=N-1;
        if(i==l) l++;
        else if(i==r) r--;

        while(l<r){
            ll cs = m[l]+m[r]+m[i];
            ll as = abs(cs);
            if(min_ > as) {
                min_ = as;
                a = m[l];
                b = m[r];
                c = m[i];
            }
            if(cs<0) {
                l++;
                if(i==l) l++;
                else if(i==r) r--;
            }
            else if(cs>0) {
                r--;
                if(i==l) l++;
                else if(i==r) r--;
            }
            else {
                if(c<a) cout<<c<<' '<<a<<' '<<b;
                else if(a<=c && c<b) cout<<a<<' '<<c<<' '<<b;
                else cout<<a<<' '<<b<<' '<<c;
                return 0;
            }
        }
    }
    if(c<a) cout<<c<<' '<<a<<' '<<b;
    else if(a<=c && c<b) cout<<a<<' '<<c<<' '<<b;
    else cout<<a<<' '<<b<<' '<<c;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m[1000001]{};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T,K,n;
    cin>>T;
    
    while(T--){
        priority_queue<ll> pq;
        cin>>K;
        for(ll i=0; i<K; i++) {
            cin>>n;
            pq.push(-n);
        }
        ll sum=0, a, b;
        while(pq.size()>1){
            a = -pq.top(); pq.pop();
            b = -pq.top(); pq.pop();
            sum+=(a+b);
            pq.push(-a-b);
        }
        cout<<sum<<'\n';
    }
}
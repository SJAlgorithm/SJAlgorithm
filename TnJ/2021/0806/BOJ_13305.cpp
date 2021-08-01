#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll N;
ll city[100001]{};
ll road[100001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=0; i<N-1; i++) cin>>road[i];
    for(ll i=0; i<N; i++) cin>>city[i];

    ll mp = INF;
    ll res = 0;
    for(ll i=0; i<N-1; i++){
        mp = min(mp, city[i]);
        res += mp*road[i];
    }

    cout<<res;
}
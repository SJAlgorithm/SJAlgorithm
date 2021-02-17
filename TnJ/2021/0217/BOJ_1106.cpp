#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000LL;

ll dp[1001]{};
vector<pair<ll,ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll C,N,a,b;
    cin>>C>>N;
    for(ll i=0; i<1001; i++) dp[i] = INF;
    for(ll i=0; i<N; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    dp[0] = 0;
    for(auto val : v){
        ll x = val.first; // cost
        ll y = val.second; // cos num
        
        for(ll i=y; i<C+101; i++){
            dp[i] = min(dp[i], dp[i-y] + x);
        }
    }
    
    ll ans = INF;
	for(int i=C; i<C+101; i++) ans = min(ans, dp[i]);
	cout<<ans;
}
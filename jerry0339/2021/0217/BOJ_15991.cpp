#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;

ll dp[100001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T,n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    for(ll i=6; i<100001; i++){
        dp[i] = (dp[i-2] + dp[i-4] + dp[i-6])%MOD;
    }

    cin>>T;
    while(T--){
        cin>>n;
        cout<<dp[n]<<'\n';
    }

}
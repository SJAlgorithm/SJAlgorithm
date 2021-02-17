#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;

ll dp[100001][4]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T,n;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(ll i=4; i<100001; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2])%MOD;
    }

    cin>>T;
    while(T--){
        cin>>n;
        cout<<(dp[n][1]+dp[n][2]+dp[n][3])%MOD<<'\n';
    }

}
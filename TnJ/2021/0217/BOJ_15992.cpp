#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;

ll dp[1001][1001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T,N,M;
    cin>>T;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    for(ll i=4; i<1001; i++){
        for(ll j=2; j<=i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1])%MOD;
        }
    }

    while(T--){
        cin>>N>>M;
        cout<<dp[N][M]<<'\n';
    }

}
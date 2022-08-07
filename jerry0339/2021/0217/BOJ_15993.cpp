#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;

ll dp[100001][2]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T,N;    
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 2;
    dp[3][1] = 2;
    for(ll i=4; i<100001; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-2][1] + dp[i-3][1])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-2][0] + dp[i-3][0])%MOD;
    }
    
    cin>>T;
    while(T--){
        cin>>N;
        cout<<dp[N][1]<<' '<<dp[N][0]<<'\n';
    }

}
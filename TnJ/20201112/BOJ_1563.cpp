// <개근상> - BOJ_1563
// DP

#include <bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x))
#define rall(v) (v).rbegin(), (v).rend()
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
const ll MOD = 1e6;

int N;
ll dp[1002][3][2]{};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N;
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i=2; i<=N; i++){
        dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0])%MOD;
        dp[i][0][1] = (dp[i][0][0] + dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1])%MOD;
        dp[i][1][0] = (dp[i-1][0][0])%MOD;
        dp[i][1][1] = (dp[i-1][0][1])%MOD;
        dp[i][2][0] = (dp[i-1][1][0])%MOD;
        dp[i][2][1] = (dp[i-1][1][1])%MOD;
    }
    
    ll ans = 0;
    for(int i=0; i<3; i++) for(int j=0; j<2; j++) ans+=dp[N][i][j];
    cout<<ans%MOD;
	
}
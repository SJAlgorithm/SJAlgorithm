// <괄호> - BOJ_10422
// DP - 카탈란 수

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int T,max_=0;
long long dp[5001]={1,0,1};
int st[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i=0; i<T; i++) {
        cin>>st[i];
        if(st[i] > max_) max_ = st[i];
    }

    for (int i=3; i<=max_; i++) {
        for (int j=2; j<=i; j++) {
            
            if (j - 2 >= 0 && i-j >= 0) {
                dp[i] += dp[j-2] * dp[i-j];
                dp[i] = dp[i] % MOD;
            }
        }
    }

    for(int i=0; i<T; i++) {
        cout<<dp[st[i]]<<'\n';
    }

}
// <Coins> - BOJ_3067
// DP

#include<bits/stdc++.h>
using namespace std;

int coin[21];
int dp[10004]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T,N,c,M;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>N;
        for(int i=0; i<N; i++) cin>>coin[i];
        cin>>M;
        for(int i=0; i<N; i++){
            dp[coin[i]]++; // optimization
            for(int j=coin[i]+1; j<=M; j++){ // optimization
                dp[j] += dp[j - coin[i]];
            }
        }
        cout<<dp[M]<<'\n';
    }
}

/*
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>N;
        for(int i=0; i<N; i++) cin>>coin[i];
        cin>>M;
        dp[0] = 1;
        for(int i=0; i<N; i++){
            for(int j=1; j<=M; j++){
                if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
            }
        }
        cout<<dp[M]<<'\n';
    }
*/
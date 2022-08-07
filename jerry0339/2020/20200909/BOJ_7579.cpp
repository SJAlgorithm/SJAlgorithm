// <앱> - BOJ_7579
// DP - 냅색

#include<bits/stdc++.h>
using namespace std;

int N,M,sum=0;
int m[101]{}, c[101]{};
int dp[10001]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>m[i];
    for(int i=0; i<N; i++) {
        cin>>c[i];
        sum+=c[i];
    }

    for(int i=0; i<N; i++){
        for(int j=sum; j>=c[i]; j--){
            dp[j] = max(dp[j], dp[j-c[i]]+m[i]);
        }
    }
    
    for(int i=0; i<=sum; i++) {
        if(dp[i]>=M) {cout<<i; break;}
    }

}
#include<bits/stdc++.h>
using namespace std;

int T,N,D,K;
int m[1000002]{};
int mm[1000002]{};
int dp[1000002][11]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T>>N>>D>>K;
    for(int i=1; i<=N; i++) cin>>m[i];
    sort(m, m+N+1);

    for(int i=1; i<=N; i++) {
        mm[i] = i - (lower_bound(m+1, m+N+1, m[i]-D+1)-m) + 1;
    }

    for(int j=1; j<=K; j++) {
        for(int i=1; i<=N; i++) {
            int t = mm[i];
            dp[i][j] = max({dp[i-1][j], t + dp[i-t][j-1]});
        }
    }

    int max_ = 0;
    for(int i=0; i<=N; i++) max_ = max(max_, dp[i][K]);
    cout<<max_;
}
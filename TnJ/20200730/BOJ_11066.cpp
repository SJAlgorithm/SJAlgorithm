// <파일 합치기> - BOJ_11066
// dp

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int T,k,i;
int dp[501][501];
int cost[501];
int sum[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while (T--) {
        cin>>k;
        for (i=1; i<=k; i++) {
            cin>>cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
 
        for (int i=1; i<k; i++) {
            for (int x=1; x+i<=k; x++) {
                int y = x+i;
                dp[x][y] = INF;
 
                for (int mid=x; mid<y; mid++)
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]);
            }
        }
        cout<<dp[1][k]<<'\n';
    }
}
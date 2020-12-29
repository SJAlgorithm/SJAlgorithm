// <파일 합치기> - BOJ_11066
// DP, 재귀
// 재귀함수를 이용한 분할로 DP수행.
// 재귀함수에서 메모이제이션을 수행하는 코드 확인(재귀함수 시간줄이기)

#include<bits/stdc++.h>
using namespace std;

int T,N;
int cost[501]{};
int ps[501]{};
int dp[501][501]{};
const int INF = 1e9;

int go(int l, int r){
    // 재귀함수를 이용할때 아래의 코드처럼 재귀함수를 호출하고나서 메모이제이션을 수행하면 소요시간이 큼
    // 따라서 아래의 for문에서 x,y부분처럼 호출전에 검사를 해주는것이 훨씬 빠름. (이 문제에서는 2배차이남)
    //if(dp[l][r] != INF) return dp[l][r];
    if(l==r) return 0;
    if(l+1==r) return cost[l] + cost[r];
    dp[l][r] = INF;
    for(int mid=l; mid<r; mid++){
        // x,y부분
        int x = dp[l][mid] == -1 ? go(l,mid) : dp[l][mid];
        int y = dp[mid+1][r] == -1 ? go(mid+1,r) : dp[mid+1][r];
        dp[l][r] = min(dp[l][r], x+y+ps[r]-ps[l-1]);
        //dp[l][r] = min(dp[l][r], go(l,mid) + go(mid+1,r) +ps[r]-ps[l-1]);
    }

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;

    while(T--){
        cin>>N;
        //memset(dp,0x7f,sizeof(dp)); -> 재귀함수 첫줄에 INF검사할때
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=N; i++){
            cin>>cost[i];
            ps[i] = ps[i-1] + cost[i];
        }
        cout<<go(1,N)<<'\n';
    }
}
// <파일 합치기> - BOJ_11066
// DP
// dp[x][y] : x~y까지의 파일을 합쳤을때의 비용
// O(N^3)풀이 -> dp[x][y] 에서 x~y의 간격이 2일때부터 dp[1][N]까지 차례대로 모든 dp[x][y]를 구해 나감. (x==y일때는 비용이 0이므로 계산x)

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f; // 1e9보다 느림

int T,N;
int cost[501]{};
int ps[501]{};
int dp[501][501]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        //memset(dp,0,sizeof(dp));
        for(int i=1; i<=N; i++){
            cin>>cost[i];
            ps[i] = ps[i-1] + cost[i];
        }
        
        for(int k=1; k<N; k++){
            for(int x=1; x+k<=N; x++){
                int y = x+k;
                dp[x][y] = INF;
                for(int mid=x; mid<y; mid++){
                    dp[x][y] = min(dp[x][y], dp[x][mid]+dp[mid+1][y]+ps[y]-ps[x-1]);
                }
            }
        }
        cout<<dp[1][N]<<'\n';
    }
}
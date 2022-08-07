// 우주탐사선 - BOJ_17182
// 간선 0이 올 수 있는데 못보고 풀어서 삽질함...
// N이 10이라서 DFS를 이용한 O(10!) 풀이도 가능함

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N,K;
int fw[10][10]{};
int dp[1<<10][10]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    memset(fw,0x3f,sizeof(fw));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>fw[i][j];
        }
    }

    // Floyd -Warshall
    for(int z=0; z<N; z++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(fw[i][z] + fw[z][j] < fw[i][j])
                    fw[i][j] = fw[i][z] + fw[z][j];
            }
        }
    }

    // TSP
    memset(dp,0x3f,sizeof(dp));
    dp[1<<K][K] = 0;
    for(int x=(1<<K)+1; x<(1<<N); x++){
        if(!(x&(1<<K))) continue;
        for(int i=0; i<N; i++){
            if((i==K) || !(x&(1<<i))) continue;
            int pre = x^(1<<i);
            for(int j=0; j<N; j++){
                if(!(pre&(1<<j))) continue;
                dp[x][i] = min(dp[x][i], dp[pre][j]+fw[j][i]);
            }
        }
    }

    int res=INF;
    for(int i=0; i<N; i++){
        if(i==K) continue;
        res = min(res, dp[(1<<N)-1][i]);
    }
    cout<<res;
}
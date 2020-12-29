// <욕심쟁이 판다> - BOJ_1937
// 그래프 탐색

#include<bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;

int N;
int m[501][501]{};
int dp[501][501]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int solve(int cy, int cx){
    if(dp[cy][cx]) return dp[cy][cx];
    for(int i=0; i<4; i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
        if(m[ny][nx] <= m[cy][cx]) continue;
        dp[cy][cx] = max(dp[cy][cx], solve(ny,nx)+1);
    }
    return dp[cy][cx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
        }
    }
    int m=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dp[i][j]==0) m = max(m,solve(i,j));
        }
    }

    cout<<m+1;
}
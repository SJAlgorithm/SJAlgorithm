#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maze[1001][1001];
int dp[1001][1001];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m,n;
    cin>>m>>n;
    int mx=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>maze[i][j];
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(maze[i][j]==0){
                dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                mx=max(mx,dp[i][j]);
            }
        }
    }
    
    cout<<mx;
    
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int MAX=500;
const int INF=987654321;

pair<int,int> maze[MAX];
int dp[MAX][MAX];

int solve(int st,int end){
    if(st==end){
        return 0;
    }
    
    if(dp[st][end]!=-1){
        return dp[st][end];
    }
    
    dp[st][end]=INF;
    
    for(int i=st;i<end;i++){
        dp[st][end]=min(dp[st][end],solve(st,i)+solve(i+1,end)+maze[st].first*maze[i].second*maze[end].second);
    }
    
    return dp[st][end];
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>maze[i].first>>maze[i].second;
    }
    memset(dp,-1,sizeof(dp));
	cout << solve(0,n-1)<<"\n";
}
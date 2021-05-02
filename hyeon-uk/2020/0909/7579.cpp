#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000000001
using namespace std;

int dp[101][10001];
int weight[101],cost[101];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    
    int result=MAX;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            if(j-cost[i]>=0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-cost[i]]+weight[i]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            if(dp[i][j]>=m){
                result=min(result,j);
            }
        }
    }
    cout<<result;
    return 0;
}


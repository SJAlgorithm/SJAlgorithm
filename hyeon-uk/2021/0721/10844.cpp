#include <algorithm>
#include<iostream>
#define MOD 1000000000

using namespace std;


long long dp[101][11]={0};

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=9;i++) dp[1][i]=1;
    
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<=9;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
    }
    long long sum=0;
    for(int i=0;i<=9;i++){
        sum+=dp[n][i];
    }
    cout<<sum%MOD<<"\n";
}
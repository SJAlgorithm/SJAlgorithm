#include <algorithm>
#include<iostream>
using namespace std;

int coin[10001]={0};
int dp[100001]={0};


int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=coin[i];j<=k;j++){
            dp[j]=dp[j]+dp[j-coin[i]];
        }
    }
   
    cout<<dp[k];
}
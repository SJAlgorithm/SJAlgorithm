#include<cstdio>
#include<algorithm>

using namespace std;
int dp[12345];
int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++){
        int k,s;
        scanf("%d %d",&k,&s);
        for(int j=t;j>=k;j--){
            dp[j]=max(dp[j],dp[j-k]+s);
        }
    }
    printf("%d",dp[t]);
    return 0;
}
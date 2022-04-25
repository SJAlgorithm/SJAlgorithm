#include<cstdio>
#define MAX 1000000009

int dp[2][1000001];

using namespace std;
int main(){
    dp[1][1]=1;dp[0][2]=1;dp[1][2]=1;dp[0][3]=2;dp[1][3]=2;
    for(int i=4;i<=1000000;i++){
            dp[0][i]=((dp[1][i-1]+dp[1][i-2])%MAX+dp[1][i-3])%MAX;
            dp[1][i]=((dp[0][i-1]+dp[0][i-2])%MAX+dp[0][i-3])%MAX;
    }
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d %d\n",dp[1][n],dp[0][n]);
    }
    return 0;
}

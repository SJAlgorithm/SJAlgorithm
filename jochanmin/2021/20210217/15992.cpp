#include<cstdio>
#define MAX 1000000009

int dp[1001][1001];

using namespace std;
int main(){
    dp[1][1]=1;dp[2][1]=1;dp[2][2]=1;dp[3][1]=1;dp[3][2]=2;dp[3][3]=1;
    for(int i=4;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            dp[i][j]=((dp[i-1][j-1]+dp[i-2][j-1])%MAX +dp[i-3][j-1])%MAX;
        }
    }
    int n,m,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

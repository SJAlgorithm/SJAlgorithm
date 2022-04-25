#include<cstdio>
#define MAX 1000000009

int dp[100001];

using namespace std;
int main(){
    dp[1]=1;dp[2]=2;dp[3]=2;dp[4]=3;dp[5]=3;dp[6]=6;
    for(int i=7;i<=100000;i++){
        dp[i]=((dp[i-2]+dp[i-4])%MAX+dp[i-6])%MAX;
    }
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}

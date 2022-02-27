#include <cstdio>
#include <queue>
#include<cstring>
using namespace std;


int dp[100001];
int coin[]={7,5,2,1};
int main() {
	int n,cnt=0,idx=0;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	dp[0]=0;
	queue<int> q;
	q.push(1);dp[1]=1;
	q.push(2);dp[2]=1;
	q.push(5);dp[5]=1;
	q.push(7);dp[7]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(now+coin[i] <=100000 && dp[now+coin[i]]==-1){
				dp[now+coin[i]]=dp[now]+1;
				q.push(now+coin[i]);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
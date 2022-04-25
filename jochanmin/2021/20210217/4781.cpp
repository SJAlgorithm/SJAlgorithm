#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

#define MAX 5001

int n,c;
double m,p;
pair<int,int> candy[MAX];
int dp[10001];


int go(int num){
	int &ret=dp[num];
	if(ret!=-1)
		return ret;
		
	ret=0;
	for(int i=0;i<n;i++){
		if(num-candy[i].second>=0)
			ret=max(ret,candy[i].first+go(num-candy[i].second));
	}
	return ret;
}

int main(){
	while(scanf("%d %lf",&n,&m)){
		memset(dp,-1,sizeof(dp));
		if(n==0 && m==0.00) break;
		for(int i=0;i<n;i++){
			scanf("%d %lf",&c,&p);
			candy[i]={c,(int)(p*100+0.5)};
		}
		printf("%d\n",go((int)(m*100+0.5)));
	}
}
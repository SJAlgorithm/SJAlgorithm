#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1234

int n,m;
pair<int,int> arr[MAX];
int dp[MAX];


int go(int num){
	if(num<=0) return 0;
	int &ret=dp[num];
	if(ret!=-1)
		return ret;
	ret=123456789;
	for(int i=0;i<m;i++){
		ret=min(ret,arr[i].first+go(num-arr[i].second));
	}
	return ret;
}

int main(){
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		arr[i]={a,b};
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(n));
}
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[2001];
int dp[2001][2001];
int go(int l,int r,int day){
	if(l>r) return 0;
	int &ret= dp[l][r];
	if(ret != 0) return ret;
	return ret = max(arr[l] * day + go(l+1,r,day+1), arr[r]*day+ go(l,r-1,day+1));
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d",go(0,n-1,1));
	return 0;
}
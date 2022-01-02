#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[201];
	int dp[201];
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	dp[0]=1;
	for(int i=1;i<n;i++){
		int now=0;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				now= max(now,dp[j]);
			}
		}
		dp[i]=now+1;
		ans=max(ans,dp[i]);
	}
	printf("%d",n-ans);
	return 0;
}
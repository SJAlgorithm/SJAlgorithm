#include <iostream>
using namespace std;

int dp[100000][2];
int arr[100000];
int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//1. increasing sequence
	//2. decreasing sequence
	dp[0][0]=1;dp[0][1]=1;
	for(int i=1;i<n;i++){
		if(arr[i-1]<=arr[i])
			dp[i][0]=dp[i-1][0]+1;
		else
			dp[i][0]=1;
		if(arr[i-1]>=arr[i])
			dp[i][1]=dp[i-1][1]+1;
		else
			dp[i][1]=1;
	}
	int max1=0;
	int max2=0;
	for(int i=0;i<n;i++){
		if(dp[i][0]>max1){
			max1=dp[i][0];
		}
		if(dp[i][1]>max2)
			max2=dp[i][1];
	}
	printf("%d",max1>max2?max1:max2);
	return 0;
}
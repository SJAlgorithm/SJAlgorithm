#include <cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int arr[12345];
int dp[400001];

int main() {
	int n;
	int res=0;
	int base=200000;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(dp[arr[i]-arr[j]+base]){
				res++;break;
			}
		}
		for(int j=0;j<=i;j++) dp[arr[i]+arr[j]+base]++;
	}
	printf("%d",res);
	return 0;
}
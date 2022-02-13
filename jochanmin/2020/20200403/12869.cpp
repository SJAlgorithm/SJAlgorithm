#include<bits/stdc++.h>
using namespace std;
#define INF 1e+8
int arr[3];
int dp[61][61][61];
int n;
int go(int tar1,int tar2,int tar3){
	if(tar1==0 && tar2==0 && tar3==0)
		return 0;	
	int &ret =dp[tar1][tar2][tar3];
	if(ret != INF)
		return ret;
	ret=INF;
	ret=min(go(max(tar1-9,0),max(tar2-3,0),max(tar3-1,0))+1,ret);
	ret=min(go(max(tar1-9,0),max(tar2-1,0),max(tar3-3,0))+1,ret);
	ret=min(go(max(tar1-1,0),max(tar2-9,0),max(tar3-3,0))+1,ret);
	ret=min(go(max(tar1-1,0),max(tar2-3,0),max(tar3-9,0))+1,ret);
	ret=min(go(max(tar1-3,0),max(tar2-1,0),max(tar3-9,0))+1,ret);
	ret=min(go(max(tar1-3,0),max(tar2-9,0),max(tar3-1,0))+1,ret);
	return ret;
}
int main() {
	for(int i=0;i<61;i++){
		for(int j=0;j<61;j++){
			for (int k=0;k<61;k++){
				dp[i][j][k]=INF;
			}
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d",go(arr[0],arr[1],arr[2]));
	return 0;
}
#include <cstdio>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	int n;
	int arr[10001];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		int ret=0;
		ret= max(ret,arr[1]-arr[0]);
		ret= max(ret,arr[n-1]-arr[n-2]);
		for(int i=0;i<n-2;i++) ret=max(ret,arr[i+2]-arr[i]);
		printf("%d\n",ret);
	}
	return 0;
}
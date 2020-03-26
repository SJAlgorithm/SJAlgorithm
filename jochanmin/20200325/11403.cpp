#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int arr2[101][101];
void srh(int *vi,int node,int n){
	for(int i=1;i<=n;i++){
		if(node==i)
		 continue;
		 if(arr[node][i] && !vi[i])
			{
				vi[i]=1;
				srh(vi,i,n);
			}
	}
	
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int num;scanf("%d",&num);
				if(num){
				 arr[i][j]=1;
				}
		}
	}
	for(int i=1;i<=n;i++)
	 srh(*(arr2+i),i,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
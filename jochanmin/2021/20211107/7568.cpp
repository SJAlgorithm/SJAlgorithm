//* 자신보다 더 "큰 덩치"의 사람의 수가 중요 
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;


ii arr[50];
int ret[50];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		arr[i]=make_pair(x,y);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].first<arr[j].first && arr[i].second<arr[j].second)
			 ret[i]++;
			if(arr[i].first>arr[j].first && arr[i].second>arr[j].second)
			 ret[j]++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",ret[i]+1);
	}
	
	return 0;
}
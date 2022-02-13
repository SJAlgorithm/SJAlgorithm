#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int arr[16];
bool visit[16];
int ans;
int n,m;
void calc(){
	int sum=0,tmp=0;
	for(int i=0;i<n;i++){
		tmp=0;
		for(int j=0;j<m;j++){
			if(visit[i*m+j]){
				tmp*=10;
				tmp+=arr[i*m+j];
			}else{
				sum+=tmp;
				tmp=0;
			}
		}
		sum+=tmp;
	}
	for(int j=0;j<m;j++){
		tmp=0;
		for(int i=0;i<n;i++){
			if(!visit[i*m+j]){
				tmp*=10;
				tmp+=arr[i*m+j];
			}else{
				sum+=tmp;
				tmp=0;
			}
		}
		sum+=tmp;
	}
	ans=max(ans,sum);
}
void dfs(int idx){
	if(idx==n*m){
		calc();
		return;
	}
	visit[idx]=true;
	dfs(idx+1);
	visit[idx]=false;
	dfs(idx+1);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[m*i+j]);
		}
	}
	
	dfs(0);
	printf("%d",ans);
	return 0;
}
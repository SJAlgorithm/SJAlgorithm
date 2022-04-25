#include <cstdio>
#include <vector>
#include<cstring>
using namespace std;

int ret=0;
vector<int> arr[100001];
bool visit[100001];
int node;
void dfs(int x,int depth){
	if(ret<depth){
		ret=depth;
		node=x;
	}
	visit[x]=true;
	for(int i=0;i<arr[x].size();i++){
		int next = arr[x][i];
		if(!visit[next]){
			dfs(next,depth+1);
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	dfs(1,0);
	ret=-1;
	memset(visit,0,sizeof(visit));
	dfs(node,0);
	printf("%d",(1+ret)/2);
	return 0;
}
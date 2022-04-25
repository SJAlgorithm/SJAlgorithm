#include <cstdio>
#include <vector>
#include<cstring>
using namespace std;
vector<int> tree[500001];
bool visit[500001];
int cnt;
void dfs(int now,int depth){
	visit[now]=true;
	if(tree[now].size()==1) cnt+=depth;
	for(int i=0;i<tree[now].size();i++){
		if(!visit[tree[now][i]]){
			dfs(tree[now][i],depth+1);
		}
	}
}
int main() {
	int n;
	int u,v;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1,0);
	if(cnt%2==1) printf("Yes");
	else printf("No");
	
	return 0;
}
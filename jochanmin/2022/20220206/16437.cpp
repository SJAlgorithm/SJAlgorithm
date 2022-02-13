#include <cstdio>
#include<vector>
using namespace std;

long long result[123457];
vector<int> tree[123457];
long long dfs(int now){
	long long ret=0;
	for(int i=0;i<tree[now].size();i++){
		ret+=dfs(tree[now][i]);
	}
	ret+=result[now];
	if(ret<0)ret=0;
	return ret;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		getchar();
		char t;
		int a,p;
		scanf("%c %d %d",&t,&a,&p);
		if(t=='W') result[i]=a*-1;
		else result[i]=a;
		tree[p].push_back(i);
	}
	long long ret = dfs(1);
	printf("%lld",ret);
	return 0;
}
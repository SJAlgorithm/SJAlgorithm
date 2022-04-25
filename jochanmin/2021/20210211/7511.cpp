#include <cstdio>
#include<vector>
#include<set>
using namespace std;
int parent[1000001];
int find(int x){
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}
void union2(int x,int y){
  x = find(x);
  y = find(y);
  if (x!=y)
    parent[y] = x;
}

int main() {
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++){
		int n,k;
		scanf("%d\n%d",&n,&k);
		for(int i=0;i<n;i++) parent[i]=i;
		while(k--){
			int u,v;
			scanf("%d%d",&u,&v);
			union2(u,v);
		}
		scanf("%d",&k);
		printf("Scenario %d:\n",cnt);
		while(k--){
			int u,v;
			scanf("%d%d",&u,&v);
			if(find(v)==find(u)){
				printf("1\n");
			}else printf("0\n");
		}
		printf("\n");
	}
	return 0;
}
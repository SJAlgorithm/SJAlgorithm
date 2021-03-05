#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,q,t,k;
int cnt[100001];
vector<pair<int,int>> vii;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int u,v;scanf("%d %d",&u,&v);
		vii.push_back({u,v});
		cnt[u]++;cnt[v]++;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&t,&k);
		if(t==1){
			if(cnt[k]>1)
				printf("yes\n");
			else
				printf("no\n");
		}else if(t==2){
			printf("yes\n");
		}
	}
}
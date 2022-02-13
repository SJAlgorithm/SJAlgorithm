#include <cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;


int main() {
	int n,k;
	
	while(scanf("%d %d",&n,&k)){
		if(n==0 && k==0) break;
		int node[1001];
		int parent[1001];
		int storedK=0;
		for(int i=0;i<n;i++){
			scanf("%d",&node[i]);
			if(node[i]==k)
			 storedK=i;
		}
		int current=parent[0]=-1;
		for(int i=1;i<n;i++){
			if(node[i]!=node[i-1]+1)
			 current++;
			parent[i]=current;
		}
		
		int cousins=0;
		if(parent[storedK] !=-1){
			for(int i=1;i<n;i++){
				if(parent[parent[i]]==parent[parent[storedK]] && parent[i] !=parent[storedK])
					cousins++;
			}
			
		}
		printf("%d\n",cousins);
		
		
	}
	
	
	return 0;
}
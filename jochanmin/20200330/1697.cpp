#include<bits/stdc++.h>
using namespace std;
bool visit[100001];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	queue<pair<int,int>> q;
	q.push({n,0});
	visit[n]=true;
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			int node=q.front().first;
			int cnt=q.front().second;
			q.pop();
			if(node==k){
				printf("%d\n",cnt);
				exit(0);
			}
			int move[]={node+1,node-1,node*2};
			for(int j=0;j<3;j++){
				if(move[j]>=0 && move[j]<=100000 && !visit[move[j]]){
					q.push({move[j],cnt+1});
					visit[move[j]]=true;
				}
			}
		}
	}
	return 0;
}
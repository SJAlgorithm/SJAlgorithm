#include <bits/stdc++.h>
#define INF 1000000004
using namespace std;

vector<pair<int,int>> vii[5001];
int cnt;
bool visit[5001];

void recom(int k,int v,int v_min){
	int tmp=v_min;
	for(int i=0;i<vii[v].size();i++){
		v_min=tmp;
		if(!visit[vii[v][i].first]){
			visit[vii[v][i].first]=true;
			v_min=min(v_min,vii[v][i].second);
			if(v_min>=k){
				cnt++;
			recom(k,vii[v][i].first,v_min);
            }
		}
	}
	
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n-1;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		vii[u].push_back(make_pair(v,w));
		vii[v].push_back(make_pair(u,w));
	}
	for(int i=0;i<q;i++){
		memset(visit,false,sizeof(visit));
		cnt=0;
		int k,v;
		scanf("%d %d",&k,&v);
		visit[v]=true;
		recom(k,v,INF);
		printf("%d\n",cnt);
	}
	return 0;
}
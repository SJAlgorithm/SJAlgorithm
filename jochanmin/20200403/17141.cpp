#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int map_o[51][51];
int map_c[51][51];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<pair<int,int>> virus;
vector<pair<int,int>> virus_point;
bool flag;int cnt=2147483645;
void copyMap(int (*src)[51],int (*dst)[51]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			src[i][j]=dst[i][j];
		}
	}
}
void bfs(){
	copyMap(map_c,map_o);
	queue<pair<int,int>> qii;
	int vSize=virus_point.size();
	for(int i=0;i<vSize;i++){
		qii.push(virus_point[i]);
		map_c[virus_point[i].first][virus_point[i].second]=0;
	}
	while(!qii.empty()){
		int x=qii.front().first;
		int y=qii.front().second;
		qii.pop();
		for(int i=0;i<4;i++){
			int cx=x+dx[i];
			int cy=y+dy[i];
			if(cx>=0 && cy < n && cy>=0 && cx<n){
				if(map_c[cx][cy]!=-2 && map_c[cx][cy]==-1){
					map_c[cx][cy]=map_c[x][y]+1;
					qii.push({cx,cy});
				}
			}
		}
	}
	int sum=0;bool flag_chk=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map_c[i][j]==-1)
			 flag_chk=true;
			sum=max(sum,map_c[i][j]);
		}
	}
	if(!flag_chk)
	 cnt=min(sum,cnt);
	if(!flag_chk)
	 flag=true;
}
void combi(){
	//virus -2가 들어있는 좌표의 개수
	int sizeV=virus.size();
	vector<int> ind;
	for(int i=0;i<m;i++)
		ind.push_back(1);
	for(int i=0;i<sizeV-m;i++)
		ind.push_back(0);
	sort(ind.begin(),ind.end());
	int sizeI=ind.size();
	do{
		for(int i=0;i<sizeI;i++){
			if(ind[i]==1){
				virus_point.push_back(virus[i]);
			}
		}
		bfs();
		for(int i=0;i<m;i++){
			virus_point.pop_back();
		}
	}while(next_permutation(ind.begin(), ind.end()));
}
int main() {
	memset(map_o,-1,sizeof(map_o));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1)
				map_o[i][j]=-2;
			if(arr[i][j]==2){
			 virus.push_back({i,j});
			}
		}
	}
	combi();
	if(!flag)
	 printf("-1");
	else{
		printf("%d",cnt);
	}
	return 0;
}
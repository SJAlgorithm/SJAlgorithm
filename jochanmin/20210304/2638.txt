#include <cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

#define NOCHEEZE 0 
#define CHEEZE 1 
#define OUTBOUND 2 
#define INBOUND 3 
#define VISITED 4 

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int arr[101][101];
int visit[101][101];
int n,m;
bool check=false;
vector<pair<int,int>> meltedCheeze;

void DrawOutBoundDfs(int row,int col){
	visit[row][col]=VISITED;
	
	for(int i=0;i<4;i++){
		int drow=row+dx[i];
		int dcol=col+dy[i];
		if(drow<0 || drow >=n || dcol<0 || dcol>=m)
			continue;
		else if(visit[drow][dcol]==VISITED) continue;
		else if(arr[drow][dcol]!=CHEEZE)
		{
			arr[drow][dcol]=OUTBOUND;
			visit[drow][dcol]=VISITED;
			DrawOutBoundDfs(drow,dcol);
		}
		 
	}
	
}
void LoadMeltedCheeze(){
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if(arr[i][j]==CHEEZE){
				int cnt=0;
				check=true;
				for(int k=0;k<4;k++){
					int ci=i+dx[k];
					int cj=j+dy[k];
					if(ci<0 || ci >=n || cj<0 || cj>=m) continue;
					if(arr[ci][cj]==OUTBOUND) cnt++;
				}
				if(cnt>=2) meltedCheeze.push_back({i,j});
			}
		}
	}
}
void DelMeltedCheeze(){
	for(int i=0;i<meltedCheeze.size();i++){
		int row=meltedCheeze[i].first;
		int col=meltedCheeze[i].second;
		arr[row][col]=NOCHEEZE;
	}
}
void InitMap(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==OUTBOUND){
				arr[i][j]==NOCHEEZE;
			}
		}
	}
}
int main() {
	int time=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	while(true){
		check=false;
		memset(visit,false,sizeof(visit));
		InitMap();
		meltedCheeze.clear();
		DrawOutBoundDfs(0,0);
		LoadMeltedCheeze();
		DelMeltedCheeze();
		if(check) time++;
		else break;
	}
	printf("%d\n",time);
	
	
	return 0;
}
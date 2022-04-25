#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int r,c;
int sheep,wolf;
char arr[277][277];
bool visit[277][277];

int dx []={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(int i,int j){
	int cur_sheep=0,cur_wolf=0;
	queue<pair<int,int>> q;
	q.push({i,j});
	visit[i][j]=true;
	if(arr[i][j]=='k') cur_sheep++;
	if(arr[i][j]=='v') cur_wolf++;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int cx=x+dx[i];
			int cy=y+dy[i];
			
			if(cx>=0 && cy>=0 && cx<r && cy<c){
				if(arr[cx][cy]!='#' && !visit[cx][cy]){
					visit[cx][cy]=true;
					q.push({cx,cy});
					if(arr[cx][cy]=='k') cur_sheep++;
					if(arr[cx][cy]=='v') cur_wolf++;
				}
			}
		}
	}
	if(cur_sheep > cur_wolf) sheep+=cur_sheep;
	else wolf+=cur_wolf;
}
int main() {
	scanf("%d %d",&r,&c);
	getchar();
	for(int i=0;i<r;i++){
		scanf("%s",arr[i]);
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]!='#'){
				if(!visit[i][j]){
					bfs(i,j);
				}
			} 
		}
	}
	printf("%d %d",sheep,wolf);
	return 0;
}
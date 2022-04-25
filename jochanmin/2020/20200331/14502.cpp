#include<bits/stdc++.h>

using namespace std;
int arr[8][8];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int ret;
vector<pair<int,int>> young;
vector<pair<int,int>> e;
void copyMap(int (*src)[8], int (*dest)[8]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dest[i][j] = src[i][j];
        }
    }
}
void go(){
	queue<pair<int,int>> two;
	for(int i=0;i<e.size();i++){
		two.push(e[i]);
	}
	int map[8][8];
	copyMap(arr, map);
	while(!two.empty()){
		int x=two.front().first;
		int y=two.front().second;
		two.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || ny<0 || nx>=n || ny>=m)    
                continue;
			if(map[nx][ny]==0){
				map[nx][ny]=2;
				two.push({nx,ny});
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0)
				cnt++;
		}
	}
	ret=max(ret,cnt);
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==0)
				young.push_back({i,j});
			else if(arr[i][j]==2)
				 e.push_back({i,j});
		}
	}
	int size=young.size();
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			for(int k=j+1;k<size;k++){
				arr[young[i].first][young[i].second]=1;
				arr[young[j].first][young[j].second]=1;
				arr[young[k].first][young[k].second]=1;
				go();
				arr[young[i].first][young[i].second]=0;
				arr[young[j].first][young[j].second]=0;
				arr[young[k].first][young[k].second]=0;
			}
		}
	}
	printf("%d",ret);
    return 0;
}
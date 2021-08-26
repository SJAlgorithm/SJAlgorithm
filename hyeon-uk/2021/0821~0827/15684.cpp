#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int maze[11][31]={0};
int n,m,h;
int result=4;
 
 
//i번 세로선의 결과가 i번인지 확인
bool check(){
    for(int i=1;i<=n;i++){
        int now=i;
        int goal=i;
        
        for(int j=1;j<=h;j++){
            if(maze[now][j]==1){
                now++;
            }
            else if(maze[now-1][j]==1){
                now--;
            }
        }
        
        if(now!=goal){
            return false;
        }
    }
    return true;
}
 
void dfs(int line,int cnt){
    //3개이상이면 어차피 불가능과 같은 출력이므로 return
    if(cnt>3){
        return;
    }
    //결과가 맞으면 result갱신
    if(check()){
        result=min(result,cnt);
    }
    
	
    for(int j=line;j<=h;j++){
        for(int i=1;i<n;i++){
        	//해당 가로선이 없으면 백트래킹
            if(maze[i][j]==0&&maze[i-1][j]==0){
                maze[i][j]=1;
                dfs(j,cnt+1);
                maze[i][j]=0;
            }
        }
    }
}
 
int main() {
    cin>>n>>m>>h;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        maze[b][a]=1;//a번 가로선에 b와b+1사이에 가로선이 있다.
    }
    dfs(1,0);
    cout<<(result==4?-1:result);
  
	return 0;
}
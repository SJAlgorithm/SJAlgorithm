#include<iostream>
#include<algorithm>
using namespace std;

char maze[201][201];
int t[201][201]={0};//설치된 시간
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int r,c,n;

bool isIn(int i,int j){
    return (i>=0&&i<r&&j>=0&&j<c);
}

void solve(){
    int time=2;
    while(time<=n){
        //채우기
        if(time%2==0){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(maze[i][j]=='.'){
                        maze[i][j]='O';
                        t[i][j]=time;
                    }
                }
            }
        }
        //터치기
        else{
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(t[i][j]+3==time){
                        for(int ii=0;ii<4;ii++){
                            int ni=i+mv[ii][0];
                            int nj=j+mv[ii][1];
                            
                            if(isIn(ni,nj)&&maze[ni][nj]!='.'){
                                maze[ni][nj]='.';
                            }
                        }
                        maze[i][j]='.';
                        t[i][j]=0;
                    }
                }
            }
        }
        time++;
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<maze[i][j];
        }
        cout<<"\n";
    }
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>r>>c>>n;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='O'){
                t[i][j]=0;
            }
        }
    }
    
    solve();    
	return 0;
}
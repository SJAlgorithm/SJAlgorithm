#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int r,c;
pair<int,int> st;
char maze[1000][1000];
int visited[1000][1000];
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int>> J,F;


void input(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='J'){
                J.push({i,j});
            }
            if(maze[i][j]=='F'){
                F.push({i,j});
            }
        }    
    }
}

bool isIn(int i,int j){
    return i>=0&&i<r&&j>=0&&j<c;
}

bool isEscape(int i,int j){
    return i==0||i==r-1||j==0||j==c-1;
}

void solve(){
    while(true){
        int fireSize=F.size();
        while(fireSize--){
            int i=F.front().first;
            int j=F.front().second;
            F.pop();
            
            for(int k=0;k<4;k++){
                int ni=i+mv[k][0];
                int nj=j+mv[k][1];
                
                if(isIn(ni,nj)&&maze[ni][nj]!='#'&&maze[ni][nj]!='F'){
                    maze[ni][nj]='F';
                    F.push({ni,nj});
                }
            }
        }
        
        int jSize=J.size();
        if(!jSize) break;
        while(jSize--){
            int i=J.front().first;
            int j=J.front().second;
            J.pop();

            if(isEscape(i,j)){
                cout<<visited[i][j]+1<<"\n";
                return;
            }

            for(int k=0;k<4;k++){
                int ni=i+mv[k][0];
                int nj=j+mv[k][1];


                if(isIn(ni,nj)&&maze[ni][nj]=='.'&&!visited[ni][nj]){
                    maze[ni][nj]='J';
                    visited[ni][nj]=visited[i][j]+1;
                    J.push({ni,nj});
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
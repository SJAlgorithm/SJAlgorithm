#include <algorithm>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

pair<int,int> jong;
vector<pair<int,int>> mad;
char maze[101][101];
int check[101][101]={0};
int mv[10][2]={{0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};
int r,c;
string str;

void input(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='I') jong={i,j};
        }
    }
    cin>>str;
}

int calc_dir(int x,int y){
    int dir=0;
    int dist=987654321;
    for(int i=1;i<=9;i++){
        int nx=x+mv[i][0];
        int ny=y+mv[i][1];
        int temp_dist=abs(jong.first-nx)+abs(jong.second-ny);
        if(temp_dist<dist){
            dist=temp_dist;
            dir=i;
        }
    }
    return dir;
}

void moving(){
    for(int i=0;i<str.size();i++){
        int dir=str[i]-'0';
        int jnx=jong.first+mv[dir][0];
        int jny=jong.second+mv[dir][1];
        
        for(int ii=0;ii<r;ii++){
            for(int jj=0;jj<c;jj++){
                if(maze[ii][jj]=='R') mad.push_back({ii,jj});
            }
        }
        
        //터지는 아두이노들을 보기위해 
        memset(check,0,sizeof(check));
        
        if(maze[jnx][jny]=='R'){
            cout<<"kraj "<<i+1<<"\n";
            return;
        }
        
        //종우 무빙
        maze[jong.first][jong.second]='.';
        maze[jnx][jny]='I';
        jong={jnx,jny};
        
        
        //매드아두이노 무빙
        for(int j=0;j<mad.size();j++){
            int x=mad[j].first;
            int y=mad[j].second;
            int mdir=calc_dir(x,y);
            
            int nx=x+mv[mdir][0];
            int ny=y+mv[mdir][1];
            
            //종우 잡음
            if(maze[nx][ny]=='I'){
                cout<<"kraj "<<i+1<<"\n";
                return;
            }
            
            //매드아두이노가 있던 위치를 . 로 변환시켜준뒤
            //매드아두이노의 다음 위치에 일단 +1을 해둠
            maze[x][y]='.';
            check[nx][ny]++;
        }
        
        // 해당 위치에 매드아두이노가 1개라면 로케이션 시키고,
        // 1개 이상이라면 폭파시킴
        for(int ii=0;ii<r;ii++){
            for(int jj=0;jj<c;jj++){
                if(check[ii][jj]>1){
                    maze[ii][jj]='.';
                }
                else if(check[ii][jj]==1){
                    maze[ii][jj]='R';
                }
            }
        }
        mad.clear();
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<maze[i][j];
        }
        cout<<"\n";
    }
}

void solve(){
    input();
    moving();
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    solve();
}

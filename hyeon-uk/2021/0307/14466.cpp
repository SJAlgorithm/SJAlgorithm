#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

vector<pair<int,int>> cow;
set<pair<int,int>> maze[101][101];
bool visited[101][101];
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,k,r;
int answer=0;

bool isIn(int a,int b){
    return (a>=1&&a<=n&&b>=1&&b<=n);
}

void dfs(int a,int b){
    if(!isIn(a,b)) return;
    
    visited[a][b]=true;
    for(int i=0;i<4;i++){
        int na=a+mv[i][0];
        int nb=b+mv[i][1];
        
        if(!visited[na][nb]&&!maze[a][b].count({na,nb})) dfs(na,nb);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k>>r;
    for(int i=0;i<r;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        maze[a][b].insert({c,d});
        maze[c][d].insert({a,b});
    }
    
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        cow.push_back({a,b});
    }
    
    for(int i=0;i<k;i++){
        memset(visited,false,sizeof(visited));
        dfs(cow[i].first,cow[i].second);
        
        for(int j=i+1;j<k;j++){
            if(!visited[cow[j].first][cow[j].second]) answer++;
        }
        
    }
    cout<<answer<<"\n";
    
    
	return 0;
}

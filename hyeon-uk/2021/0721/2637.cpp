#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> maze[101];
int parts[101][101]={0};
int indeg[101]={0};
int n,m,x,y,k;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>k;
        maze[y].push_back({x,k});
        indeg[x]++;
    }
    
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){
            q.push(i);
            parts[i][i]=1;
        }
    }
    
    while(!q.empty()){
        int now=q.front();
        q.pop();
        
        for(pair<int,int> t:maze[now]){
            int next=t.first;
            int cost=t.second;
            
            indeg[next]--;
            if(!indeg[next]) q.push(next);    
            
            for(int i=1;i<=n;i++){
                parts[i][next]+=parts[i][now]*cost;
            }
        
        }
    }
    
    for(int i=1;i<=n;i++){
        if(parts[i][n]){
            cout<<i<< " " <<parts[i][n]<<"\n";
        }
    }
}

//
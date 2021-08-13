#include<iostream>
#include<queue>
#include<string>

using namespace std;

void bfs(int a,int b){
    bool visited[10001]={0};
    queue<pair<int,string>> q;
    q.push({a,""});
    visited[a]=true;
    
    while(!q.empty()){
        int now=q.front().first;
        string now_str=q.front().second;
        q.pop();
        
        if(now==b){
            cout<<now_str<<"\n";
            return;
        }
        
        int D=(now*2)%10000;
        if(!visited[D]){
            visited[D]=true;
            q.push({D,now_str+"D"});
        }
        
        int S=(now-1<0?9999:now-1);
        if(!visited[S]){
            visited[S]=true;
            q.push({S,now_str+"S"});
        }
        
        int L=(now%1000)*10+(now/1000);
        if(!visited[L]){
            visited[L]=true;
            q.push({L,now_str+"L"});
        }
        
        int R=(now%10)*1000+(now/10);
        if(!visited[R]){
            visited[R]=true;
            q.push({R,now_str+"R"});
        }
    }
}

int main() {
	
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        bfs(a,b);
    }
    
	return 0;
}
#include<iostream>
#include<queue>
using namespace std;
 
#define MAX_VALUE 1001          
int N, M, V;                    
int mat[MAX_VALUE][MAX_VALUE];    
int visit[MAX_VALUE];        
 
void dfs(int v) {
    
    cout << v << ' ' ;
    visit[v] = 1;         
    for(int i=1; i<=N; i++) {
        if(visit[i] == 1 || mat[v][i] == 0)     
            continue;
        dfs(i);             
    }
}
 
void bfs(int v) {
    queue<int> q;            
    q.push(v);
    visit[v] = 0;           
    while(!q.empty()) {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for(int i=1; i<=N; i++) {
            if(visit[i] == 0 || mat[v][i] == 0)
                continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}
 
int main() {
    int x, y;
    cin >> N >> M >> V;         
    for(int i=0; i<M; i++) {    
        cin >> x >> y;            
        mat[x][y] = mat[y][x] = 1;   
    }
    dfs(V);            
    cout << '\n';
    bfs(V);
    return 0;
}

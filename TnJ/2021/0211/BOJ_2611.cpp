#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;

// <1948 임계경로> 와 비슷한 문제

int N,M;
vector<pii> adj[1001]{};
int deg[1001]{};
int pre[1001]{};
int dis[1001]{};

void topology(){
    queue<int> q;
    q.push(1);

    for(int i=1; i<=N; i++){
        int cn = q.front();
        q.pop();

        for(int j=0; j<adj[cn].size(); j++){
            int nn = adj[cn][j].xx;
            int nd = adj[cn][j].yy;
            if(--deg[nn]==0) q.push(nn);
            if(dis[cn] + nd > dis[nn]){
                pre[nn] = cn;
                dis[nn] = dis[cn] + nd;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        deg[b]++;
    }
    
    topology();
    cout<<dis[1]<<'\n';
    stack<int> stk;
    int n = 1;
    while(1){
        stk.push(n);
        n = pre[n];
        if(n==1) {stk.push(n); break;}
    }
    while(!stk.empty()){
        cout<<stk.top()<<' ';
        stk.pop();
    }
}
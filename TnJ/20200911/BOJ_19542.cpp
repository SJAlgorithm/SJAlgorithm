// <전단지 돌리기> - BOJ_19542
// 트리, 재귀

#include<bits/stdc++.h>
using namespace std;

int N,S,D;
vector<int> adj[100001];
bool vi[100001]{};
int info[100001][2]{};

int dis=0;
void dfs(int node, int dpt){
    info[node][0] = dpt;
    info[node][1] = dpt;

    for(int i=0; i<adj[node].size(); i++){
        int nn = adj[node][i];
        if(!vi[nn]) {
            dis++;
            vi[nn] = true;
            dfs(nn, dpt+1);
            info[node][1] = max(info[node][1], info[nn][1]);
        }
    }
    if(info[node][1] - info[node][0] >= D) dis++;
    else dis--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S>>D;
    int a, b;
    while(cin>>a>>b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi[S] = true;
    dfs(S,0);
    if(dis<0) {cout<<0; return 0;}
    cout<<dis-1;
}
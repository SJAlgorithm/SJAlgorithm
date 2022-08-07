// <북쪽나라의 도로> - BOJ_1595
// 트리, dfs
// O(N)풀이 (dfs 2번)

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

vector<pii> tree[10001]{};
bool vi[10001]{};

int dis=0, midx, ms=0;
void dfs(int node){
    for(int i=0; i<tree[node].size(); i++){
        int nn = tree[node][i].xx;
        int nd = tree[node][i].yy;
        if(!vi[nn]) {
            vi[nn] = true;
            dis += nd;
            if(dis > ms) {ms = dis; midx = nn;}
            dfs(nn);
            dis -= nd;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    int N=0;
    while(cin>>a>>b>>c){    
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    vi[a] = true;
    dfs(a);

    dis = 0;
    memset(vi,0,sizeof(vi));
    vi[midx] = true;
    dfs(midx);
    cout<<ms;
}
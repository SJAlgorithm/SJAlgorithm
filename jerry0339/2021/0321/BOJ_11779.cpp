#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int N,M;
vector<pii> adj[1001];
int d[1001]{};
int trace[1001]{};

void dijk(int st) {
    priority_queue<pii> pq;
    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cn = pq.top().yy;
        pq.pop();

        if(cd>d[cn]) continue;
        for(int i=0; i<adj[cn].size(); i++){
            int nn = adj[cn][i].xx;
            int nd = adj[cn][i].yy + cd;

            if(nd < d[nn]){
                d[nn] = nd;
                pq.push({-d[nn],nn});
                trace[nn] = cn;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    memset(d,0x3f,sizeof(d));
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    
    cin>>a>>b;
    dijk(a);

    int tmp = b;
    vector<int> stk;
    trace[a] = 0;
    while(tmp){
        stk.push_back(tmp);
        tmp = trace[tmp];
    }

    cout<<d[b]<<'\n';
    cout<<stk.size()<<'\n';
    for(int i=stk.size()-1; i>=0; i--) cout<<stk[i]<<' ';
}
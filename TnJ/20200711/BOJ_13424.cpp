// <비밀 모임> - BOJ_13424
// 다익스트라 풀이. 플로이드 와샬로도 풀림.

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define ini(x, y) memset(x, y, sizeof(x))
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL)
#define xx first
#define yy second
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int T,N,M,K;
vector<pii> adj[101];
vector<int> fr;
int d[101][101]{};

void solve(int st){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii(0,st));
    d[st][st] = 0;

    while(!pq.empty()){
        int cd = pq.top().xx;
        int cp = pq.top().yy;
        pq.pop();

        if(d[st][cp] < cd) continue;

        for(int i=0; i<adj[cp].size(); i++){
            int np = adj[cp][i].xx;
            int nd = adj[cp][i].yy + cd;

            if(nd < d[st][np]){
                d[st][np] = nd;
                pq.push(pii(nd,np));
            }
        }
    }
}

int main() {
    FASTIO;
    cin>>T;
    int a,b,c;
    while(T--){
        cin>>N>>M;
        ini(d,0x3f);
        ini(adj,0);
        fr.clear();

        while(M--){
            cin>>a>>b>>c;
            adj[a].push_back(pii(b,c));
            adj[b].push_back(pii(a,c));
        }

        cin>>K;
        while(K--){
            cin>>a;
            fr.push_back(a);
        }

        for(int st : fr){
            solve(st);
        }

        int min_= 1e9, mini=0;
        for(int i=1; i<=N; i++){
            int s = 0;
            for(int val : fr){
                s += d[val][i];
            }
            if(min_ > s) {min_ = s; mini = i;}
        }
        cout<<mini<<'\n';
    }

}
// <아기상어> - BOJ_16236
// BFS+ 우선순위큐

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define aa first
#define bb second
#define all(v) (v).begin(), (v).end()

int N, skSize=2, skAte=0, ans=0;
pii skPos;
int mp[20][20]={0,};
bool vi[20][20]={0,};
int dn[4] = {-1,0,0,1};
int dm[4] = {0,-1,1,0};

struct comp{
	bool operator()(pair<pii,pii> &a, pair<pii,pii> &b){
		if(a.aa.aa == b.aa.aa) return a.aa.bb > b.aa.bb;
        return a.aa.aa > b.aa.aa;
	}
};

bool bfs(int i, int j){
    priority_queue<pair<pii,pii>,vector<pair<pii,pii>>,comp> q;
    q.push({{0,i*10+j},{i,j}});
    vi[i][j]=true;

    while(!q.empty()){
        int cdis = q.top().aa.aa;
        int cn = q.top().bb.aa;
        int cm = q.top().bb.bb;
        q.pop();

        if(mp[cn][cm]>0 && mp[cn][cm]<skSize) {
            skAte++;
            if(skAte==skSize) {skSize++; skAte=0;}
            ans += cdis;
            mp[cn][cm] = 0;
            skPos={cn,cm};
            return true;
        }

        for(int i=0; i<4; i++){
            int nn = cn + dn[i];
            int nm = cm + dm[i];
            if(nn<0 || nm<0 || nn>=N || nm>=N || mp[nn][nm]>skSize) continue;
            if(!vi[nn][nm]){
                q.push({{cdis+1,10*nn+nm},{nn,nm}});
                vi[nn][nm] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>mp[i][j];
            if(mp[i][j]==9) {
                skPos={i,j};
                mp[i][j] = 0;
            }
        }
    }

    bool res;
    do{
        memset(vi,0,sizeof(vi));
        res = bfs(skPos.aa,skPos.bb);
    } while (res);

    cout<<ans;
}
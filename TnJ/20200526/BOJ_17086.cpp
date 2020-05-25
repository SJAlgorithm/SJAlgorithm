// <아기상어 2> - BOJ_17086
// bfs

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define aa first
#define bb second
#define all(v) (v).begin(), (v).end()

int N,M;
int m[50][50]={0,};
bool vi[50][50]={0,};
int dn[8]= {-1,-1,0,1,1,1,0,-1};
int dm[8]= {0,1,1,1,0,-1,-1,-1};
int max_=0;

int bfs(int sti, int stj){
    memset(vi,0,sizeof(vi));
    queue<pair<int,pii>> q;
    q.push({0,{sti,stj}});
    vi[sti][stj] = true;

    while(!q.empty()){
        int cn = q.front().bb.aa;
        int cm = q.front().bb.bb;
        int cd = q.front().aa;
        q.pop();

        if(m[cn][cm]) return cd;

        for(int i=0; i<8; i++) {
            int nn = cn + dn[i];
            int nm = cm + dm[i];
            if(nn<0 || nm<0 || nn>=N || nm>=M || vi[nn][nm]) continue;
            q.push({cd+1,{nn,nm}});
            vi[nn][nm] = true;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    bool flag=false;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>m[i][j];
            if(m[i][j]) flag = true;
        }
    }
    if(!flag) {
        cout<<max(N,M)-1;
        return 0;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!m[i][j]){
                max_ = max(bfs(i,j),max_);
            }
        }
    }

    cout<<max_;
}
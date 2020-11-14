// <알고스팟> - BOJ_1261
// 우선순위큐, BFS

#include <bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x))
#define rall(v) (v).rbegin(), (v).rend()
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<pii> vecpii;
typedef vector<int> veci;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;

int N,M;
int m[101][101]{};
int vi[101][101]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int dijk(){
    priority_queue<piii> pq;
    pq.push({0,{0,0}});

    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cy = pq.top().yy.xx;
        int cx = pq.top().yy.yy;
        pq.pop();

        if(cy==N-1 && cx==M-1) return cd;
        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nd = cd;
            if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx]) continue;
            if(m[ny][nx]) nd++;
            pq.push({-nd,{ny,nx}});
            vi[ny][nx] = true;
        }
    }
}

int main() {
    
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>M>>N;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            m[i][j] = str[j]-'0';
        }
    }

    cout<<dijk();
}
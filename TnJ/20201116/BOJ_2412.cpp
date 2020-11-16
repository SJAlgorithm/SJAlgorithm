// <암벽 등반> - BOJ_2412
// bfs, 이분탐색

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,T;
pii h[50001]{};
bool vi[50001]{};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>T;
    N++;
    for(int i=1; i<=N; i++) cin>>h[i].xx>>h[i].yy;
    sort(h,h+N);

    queue<pii> q;
    q.push({0,0});
    vi[0] = true;

    while(!q.empty()){
        int cd = q.front().xx;
        int ci = q.front().yy;
        int cx = h[ci].xx;
        int cy = h[ci].yy;
        q.pop();

        if(cy==T) {cout<<cd; return 0;}

        for(int i=-2; i<=2; i++){
            for(int j=-2; j<=2; j++){
                int lb = lower_bound(h,h+N,pii(cx+i,cy+j))-h;
                int ub = upper_bound(h,h+N,pii(cx+i,cy+j))-h;
                if(lb==ub) continue;
                if(vi[lb]) continue;
                q.push({cd+1,lb});
                vi[lb] = true;
            }
        }
    }
    cout<<-1;
}
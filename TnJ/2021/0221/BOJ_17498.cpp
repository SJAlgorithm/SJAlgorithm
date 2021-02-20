#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

ll N,M,D;
vector<vector<ll>> v;
vector<vector<ll>> dp;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M>>D;
    ll k;
    v.resize(N+1);
    dp.resize(N+1);
    for(ll i=0; i<N; i++) dp[i].resize(M+1,-INF);
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M; j++){
            cin>>k;
            v[i].push_back(k);
        }
    }

    for(ll j=0; j<M; j++) dp[0][j] = 0;
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M; j++){
            for(ll x=1; x<=D; x++){
                if(i+x>=N) break;
                for(ll y=(-D+1); y<D; y++){
                    if(j+y<0 || j+y>=M || x+abs(y)>D) continue;
                    ll sc = v[i][j]*v[i+x][j+y];
                    dp[i+x][j+y] = max(dp[i+x][j+y], dp[i][j]+sc);
                }
            }
        }
    }

    ll max_=-INF;
    for(ll j=0; j<M; j++) max_ = max(max_, dp[N-1][j]);
    cout<<max_;
}
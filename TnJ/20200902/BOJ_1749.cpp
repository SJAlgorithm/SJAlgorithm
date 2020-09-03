// <점수 따먹기> - BOJ_1749
// 2차원 prefix sum

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,M;
ll m[210][210]{};
ll psum[210][210]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(ll i=1; i<=N; i++) {
        for(ll j=1; j<=M; j++){
            cin>>m[i][j];
            psum[i][j] = m[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }

    for(ll i=1; i<=N; i++) {
        for(ll j=1; j<=M; j++){
            cout<<psum[i][j]<<' ';
        }cout<<'\n';
    }
    cout<<'\n';
    ll max_=LLONG_MIN;
    for(ll i=1; i<=N; i++) {
        for(ll j=1; j<=M; j++){
            for(ll x=i; x<=N; x++) {
                for(ll y=j; y<=M; y++){
                    ll t = psum[x][y] - psum[i-1][y] - psum[x][j-1] + psum[i-1][j-1];
                    max_ = max(max_, t);
                }
            }
        }
    }

    cout<<max_;
}
// 일직선상 최소 이동거리
// 일직선상에 N개의 노드들이 있고 모든 노드들로부터 거리의 합이 가장 작은 중심노드 C를 일직선상에 배치하려고 할때
// 배치될 C의 왼쪽 노드들의 개수를 L, 오른쪽 노드들의 개수를 R이라고 한다면
// (L-R)의 절대값이 가장 작은 위치가 C가 배치되어야 하는 위치임.

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF = 1e18;

ll N;
vector<pll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll a,b,sum=0;
    for(ll i=0; i<N; i++){
        cin>>a>>b;
        v.push_back({a,b});
        sum+=b;
    }
    sort(v.begin(), v.end());

    ll mPos = v[0].xx, mDist = sum-v[0].yy, t=0, tt;
    for(auto val : v){
        tt = abs((sum-t-val.yy)-t);
        if(mDist > tt) {
            mDist = tt;
            mPos = val.xx;
        }
        t += val.yy;
    }
    cout<<mPos;

}
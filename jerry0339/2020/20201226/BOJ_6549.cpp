// <히스토그램에서 가장 큰 직사각형> - BOJ_6549
// 세그트리, 분할정복

#include<bits/stdc++.h>
#define MAX 100000
#define MAX_N 100001
using namespace std;
typedef long long ll;
const ll INF = 1e10;

ll arr[MAX_N]{};
ll tree[MAX<<2]{};
ll N,Q;

// 쿼리의 결과는 최소값의 arr의 index를 구해줌
// ex) 구간의 최소값이 100이라면 arr에 100이 저장된 index반환
// arr[0]에 INF가 저장됨(배열의 최소값 초기값)
ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = s;
    ll mid = (s+e)>>1;
    ll x = init(n<<1, s, mid);
    ll y = init(n<<1|1, mid+1, e);
    if(arr[x] > arr[y]) return tree[n] = y;
    else return tree[n] = x;
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    ll x = query(n<<1, s, mid, l, r);
    ll y = query(n<<1|1, mid+1, e, l, r);
    if(arr[x] > arr[y]) return y;
    else return x;
}

// 분할정복
ll solve(ll l, ll r) {
	if (l > r) return 0; // arr[0] = INF
	ll midx = query(1, 1, N, l, r);
	ll ans = (r-l+1) * arr[midx];
	ans = max(ans, solve(l, midx - 1));
	ans = max(ans, solve(midx + 1, r));
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    arr[0] = INF;
    while(1){
        cin>>N;
        if(N==0) break;

        for(ll i=1; i<=N; i++){
            cin>>arr[i];
        }
        init(1,1,N);

        cout<<solve(1,N)<<'\n';
    }
    
    return 0;
}
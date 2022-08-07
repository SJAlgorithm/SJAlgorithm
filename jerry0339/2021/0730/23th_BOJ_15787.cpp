#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tpi = tuple<int,int,int>;
using tpl = tuple<ll,ll,ll>;
using dpi = pair<pii,pii>;
using dpl = pair<pll,pll>;
const int INF = 0x3f3f3f3f;

int N,M;
int mask[100001]{};
int vi[1<<20]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    while(M--){
        int a,b,c;
        cin>>a>>b;
        if(a==1){
            cin>>c;
            mask[b] |= 1<<(c-1);
        } else if(a==2){
            cin>>c;
            if(mask[b] & 1<<(c-1)) mask[b] ^= 1<<(c-1);
        } else if(a==3){
            mask[b] = mask[b]<<1;
            if(mask[b] & (1<<20)) mask[b] ^= 1<<20;
        } else {// a==4
            mask[b] = mask[b]>>1;
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        if(vi[mask[i]]) continue;
        vi[mask[i]] = true;
        ans++;
    }
    cout<<ans;
}
// <신입사원> - BOJ_1946

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define aa first
#define bb second
#define all(v) (v).begin(), (v).end()

int T,N;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        v.clear();
        int a,b;
        for(int i=0; i<N; i++){
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(all(v));
        int c=v[0].bb;
        int cnt=1;
        for(int i=1; i<N; i++){
            if(c<v[i].bb) continue;
            cnt++;
            c = v[i].bb;
        }
        cout<<cnt<<'\n';
    }
}
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

int N;
vector<pii> arr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int a,b;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        arr.push_back({b,a});
    }
    sort(arr.begin(), arr.end(), greater<pii>());
    
    int ans = 1;
    priority_queue<int> pq;
    pq.push(arr[0].yy);
    for(int i=1; i<N; i++){
        //if(pq.empty()) {cout<<"error"; break;}
        int cur = arr[i].xx;
        int next = pq.top();
        if(cur <= next) {
            pq.pop();
            pq.push(arr[i].yy);
        } else {
            pq.push(arr[i].yy);
            ans++;
        }
    }

    cout<<ans;
}
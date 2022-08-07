#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int N,D,K,C;
int ini[3000010]{};
int vi[3010]{};
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>D>>K>>C;
    for(int i=0; i<N; i++) cin>>ini[i];
    int cnt=0;
    for(int i=0; i<K; i++){
        dq.push_back(ini[i]);
        if(!vi[ini[i]]) cnt++;
        vi[ini[i]]++;
    }
    int ans, max_ = cnt;
    for(int i=1; i<N; i++) {
        int nN = ini[(i+K-1)%N];
        int pN = dq.front();
        dq.pop_front();
        dq.push_back(nN);
        vi[nN]++;
        if(vi[nN]==1) cnt++;
        vi[pN]--;
        if(vi[pN]==0) cnt--;
        if(!vi[C]) ans = cnt+1;
        else ans = cnt;
        max_ = max(max_, ans);
    }
    cout<<max_;
}
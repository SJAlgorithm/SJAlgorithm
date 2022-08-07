// <개똥벌레> - BOJ_3020
// 이분탐색

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()

int N,H;
vector<int> v1;
vector<int> v2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>H;
    int a,b;
    for(int i=0; i<N/2; i++) {
        cin>>a>>b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(all(v1));
    sort(all(v2));
    int min_=1e9, cnt=1;
    for(int i=1; i<=H; i++){
        int k1 = lower_bound(all(v1),i)-v1.begin();
        int k2 = upper_bound(all(v2),H-i)-v2.begin();
        int t = N-k1-k2;
        if(t<min_) {
            min_=t;
            cnt=1;
        }else if(t==min_) cnt++;
    }
    cout<<min_<<' '<<cnt;
}
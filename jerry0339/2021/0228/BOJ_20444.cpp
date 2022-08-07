#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    ll s=0, e=N/2, mid;
    while(s<=e){
        mid = (s+e)/2;
        ll sum = (mid+1)*(N-mid+1);
        if(sum > K) e = mid - 1;
        else if(sum < K) s = mid + 1;
        else {
            cout<<"YES";
            return 0;
        }
    }
    
    cout<<"NO";
}
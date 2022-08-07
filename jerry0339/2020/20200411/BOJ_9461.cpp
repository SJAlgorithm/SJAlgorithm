// <파도반 수열> - BOJ_9461

#include<bits/stdc++.h>
using namespace std;

int N;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.push_back(1); v.push_back(1); v.push_back(1);
    v.push_back(2); v.push_back(2);
    while(N--){
        int n; cin>>n;
        if(n>v.size()){
            for(int j=v.size(); j<n; j++){
                v.push_back(v[j-5]+v[j-1]);
            }
        }
        cout<<v[n-1]<<'\n';
    }

}
#include<bits/stdc++.h>
using namespace std;

int m[100010]{};
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    cin>>m[0];
    int prev = m[0], tsum = 1;
    v.push_back(0);
    for(int i=1; i<N; i++) {
        cin>>m[i];
        if(m[i]==prev) {
            v.push_back(tsum);
            tsum = 1;
        } else {
            tsum++;
        }

        prev = m[i];
    }
    v.push_back(tsum);
    v.push_back(0);

    int max_ = *max_element(v.begin(), v.end());
    for(int i=1; i<v.size()-1; i++){
        int t = v[i-1] + v[i+1] + v[i];
        max_ = max(max_, t);
    }

    cout<<max_;
}
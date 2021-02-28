// LIS 역추적 : https://www.crocus.co.kr/681
// 비슷한 문제 : https://www.acmicpc.net/problem/14003

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int N;
int m[10010]{};
int a[10010]{};
int b[10010]{};
int trace[10010]{};
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=0; i<N; i++) {
        cin>>a[i];
        b[a[i]] = i;
    }
    for(int i=0; i<N; i++) {
        cin>>t;
        m[i] = b[t];
    }

    lis.push_back(-INF);
    for (int i = 0; i < N; i++) {
        if (lis.back() < m[i]) {
            trace[i] = lis.size();
            lis.push_back(m[i]);
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), m[i]);
            trace[i] = it - lis.begin();
            *it = m[i];
        }
    }

    int length = lis.size()-1;
    cout<<length<<'\n';
    
    vector<int> ans;
    for(int i=N-1; i>=0; i--){
        if(trace[i] == length) {
            ans.push_back(i);
            length--;
            if(length < 1) break;
        }
    }

    lis.clear();
    for(int i=0; i<ans.size(); i++) lis.push_back(a[m[ans[i]]]);
    sort(lis.begin(), lis.end());
    for(auto val : lis) cout<<val<<' ';

}
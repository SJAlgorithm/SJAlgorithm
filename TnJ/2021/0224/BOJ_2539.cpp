#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,M,L,K;
vector<pii> v;

bool isP(int mid){
    int n = 1, cn = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].xx < v[cn].xx + mid) continue;
        cn = i;
        n++;
    }
    if(n<=L) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M; // 행,열
    cin>>L>>K; // 색종이, 회색칸
    int a,b,st = 0;
    for(int i=0; i<K; i++){
        cin>>a>>b;
        v.push_back({b,a});
        st = max(st, a);
    }
    sort(v.begin(), v.end());

    int s = st, e = N, mid;
    while(s<=e){
        mid = (s+e)/2;
        if(isP(mid)) e = mid - 1;
        else s = mid + 1;
    }

    cout<<s;
}
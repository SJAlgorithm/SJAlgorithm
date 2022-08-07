// <포도주 시식> - BOJ_2156
// DP

#include<bits/stdc++.h>
using namespace std;

int c[10001]={0,};
int d[10001]={0,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;

    for(int i=1; i<=n; i++) cin>>c[i];
    d[1] = c[1];
    if(n > 1) d[2] = c[1] + c[2];
    if(n > 2) {
        for(int i=3; i<=n; i++){
            d[i] = max(max(d[i-1], d[i-2]+c[i]),d[i-3]+c[i-1]+c[i]);
        } // (i: X), (i: O, i-1: X), (i: O, i-1: O, i-2: X)
    }
    cout<<d[n];
}
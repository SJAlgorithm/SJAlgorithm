// <색종이 만들기> - BOJ_2630
// Divide and Conquer

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int chk[1]={0,};

int go(int x, int y, int k){
    int a,b,c,d;
    if(k==1) return v[x][y]; // 탈출조건
    a = go(x, y, k/2);
    b = go(x,y+k/2,k/2);
    c = go(x+k/2,y,k/2);
    d = go(x+k/2,y+k/2,k/2);
    if(a==1 && b==1 && c==1 && d==1) return 1;
    else if(a==0 && b==0 && c==0 && d==0) return 0;
    else {
        if(a!=2) chk[a]++;
        if(b!=2) chk[b]++;
        if(c!=2) chk[c]++;
        if(d!=2) chk[d]++;
        return 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int t; cin>>t;
            v[i].push_back(t);
        }
    }

    k = go(0,0,n);
    if(k!=2) chk[k]++;
    cout<<chk[0]<<'\n'<<chk[1];

}
// <종이의 개수> - BOJ_1780
// 분할정복
// 인덱스접근...!! BOJ_2293(색종이)처럼 재귀를통한 반환값을 이용해도, 
// 인덱스접근코드랑 속도가 비슷하게나옴. 앞으로는 더 편한 인덱스접근을 사용하도록 하자.

#include<bits/stdc++.h>
using namespace std;

int v[2188][2188];
int cnt[2]={0,};

void go(int y, int x, int k) {
    bool flag=true;
    for(int i=y;(i<y+k)&&flag;i++)
        for(int j=x;(j<x+k)&&flag;j++)
            if (v[y][x] != v[i][j])
                flag=false;

    if (flag) cnt[++v[y][x]]++;
    else {
        k/=3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                go(y+i*k,x+j*k,k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>v[i][j];

    go(0,0,n);
    cout<<cnt[0]<<'\n'<<cnt[1]<<'\n'<<cnt[2];
}
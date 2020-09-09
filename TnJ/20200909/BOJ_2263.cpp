// <트리의 순회> - BOJ_2263
// 트리, 재귀

#include<bits/stdc++.h>
using namespace std;

int N;
int inidx[100001]{};
int postod[100001]{};

void solve(int inl, int inr, int postl, int postr){
    if(inl>inr || postl>postr) return;
    int root = postod[postr];
    cout<<root<<' ';
    int mid = inidx[root];
    solve(inl, mid-1, postl, postl+mid-inl-1);
    solve(mid+1, inr, postl+mid-inl, postr-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=1; i<=N; i++) {cin>>t; inidx[t]=i;}
    for(int i=1; i<=N; i++) cin>>postod[i];

    solve(1,N,1,N);
}

/*
in: 8 4 10 9 11 2 5 1 6 3 7
post: 8 10 11 9 4 5 2 6 7 3 1

pre : 1 2 4 8 9 10 11 5 3 6 7
*/
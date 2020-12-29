// <2+1 세일> - BOJ_11508
// Greedy

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define aa first
#define bb second

int N;
int pd[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>pd[i];
    }
    sort(pd,pd+N,greater<int>());

    int res=0;
    for(int i=0; i<N; i++){
        if(i%3==2) continue;
        res+=pd[i];
    }

    cout<<res;
}
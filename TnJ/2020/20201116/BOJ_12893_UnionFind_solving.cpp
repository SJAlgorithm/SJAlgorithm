// <적의 적> - BOJ_12893
// disjoint set 풀이

#include<bits/stdc++.h>
using namespace std;

int N,M;
int pr[2010]{}, en[2010]{};

int find(int k) {
    if (k==-1) return k;
    if (pr[k]==k) return k;
    else return pr[k] = find(pr[k]);
}

void merge(int a, int b){
    a = find(a);
    int bEnem = find(en[b]);
    if(bEnem==-1) {en[b] = a; bEnem = a;}
    pr[a] = bEnem;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) pr[i] = i;
    memset(en,-1,sizeof(en));
    int a,b;
    while(M--){
        cin>>a>>b;
        merge(a,b);
        merge(b,a);
        if(find(en[a])==find(en[b])) {cout<<0; return 0;}
    }
    
    cout<<1;
}
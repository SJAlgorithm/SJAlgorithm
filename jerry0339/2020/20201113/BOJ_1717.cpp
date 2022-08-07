// <집합의 표현> - BOJ_1717
// Union Find = 분리집합 = disjoint_set

#include<bits/stdc++.h>
using namespace std;

int N,M;
int parent[1000010]{};

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}
 
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<=N; i++) parent[i] = i;
    while(M--){
        cin>>a>>b>>c;
        if(a){
            find(b)==find(c) ? cout<<"YES\n" : cout<<"NO\n";
        }else{
            merge(b,c);
        }
    }
}
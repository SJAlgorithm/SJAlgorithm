// <여행 가자> - BOJ_1976
// Union Find

#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[202][202]{};
int parent[202]{};

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
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>m[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++){
            if(m[i][j]) merge(i,j);
        }
    }
    cin>>a;
    int t = find(a);
    bool chk = true;
    M--;
    while(M--){
        cin>>a;
        if(find(a)!=t) {
            chk = false;
            break;
        }
    }
    chk ? cout<<"YES" : cout<<"NO";
}
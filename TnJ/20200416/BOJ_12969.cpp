// <ABC> - BOJ_12969
// DFS + DP

#include<bits/stdc++.h>
using namespace std;

int N,K;
char res[31];
bool vi[436][31][31][31]= {false,};

void dfs(int k, int a, int b, int n){
    if(n==N){
        if(k==K){
            cout<<res;
            exit(0);
        }
        return;
    }
    if(k>K) return;
    vi[k][a][b][n] = true;
    if(!vi[k][a+1][b][n+1]) {res[n]='A';dfs(k,a+1,b,n+1);}
    if(!vi[k+1][a][b+1][n+1]) {res[n]='B'; dfs(k+a,a,b+1,n+1);}
    if(!vi[k+a+b][a][b][n+1]) {res[n]='C'; dfs(k+a+b,a,b,n+1);}
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    dfs(0,0,0,0);
    cout<<"-1";
}
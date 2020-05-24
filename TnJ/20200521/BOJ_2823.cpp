// <유턴 싫어> - BOJ_2823

#include<bits/stdc++.h>
using namespace std;

int N,M;
char m[11][11];
int dn[4] = {-1,1,0,0};
int dm[4] = {0,0,-1,1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    char ch;
    for(int i=0; i<N; i++){
        cin>>m[i];
    }
    int res = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(m[i][j]=='.'){
                int cnt=0;
                for(int k=0; k<4; k++){
                    int nn= i +dn[k];
                    int nm= j +dm[k];
                    if(nn<0 || nm<0 || nn>=N || nm>=M) continue;
                    if(m[nn][nm]=='.')cnt++;
                }
                if(cnt<=1) {cout<<1; return 0;}
                res = 0;
            }
        }
    }
    cout<<res;
    return 0;
}
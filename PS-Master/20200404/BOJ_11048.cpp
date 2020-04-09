// <이동하기> - BOJ_11048
// 대각선은 구하지 않아도 됨

#include<bits/stdc++.h>
using namespace std;

int N,M;
int cd[1001][1001]={0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M; 
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>cd[i][j];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!i && !j) continue;
            if(i-1 < 0){
                cd[i][j] += cd[i][j-1];
                continue;
            }
            if(j-1 < 0) {
                cd[i][j] += cd[i-1][j];
                continue;
            }
            int t = cd[i-1][j] > cd[i][j-1] ? cd[i-1][j] : cd[i][j-1];
            cd[i][j] += t;
        }
    }
    cout<<cd[N-1][M-1];
}
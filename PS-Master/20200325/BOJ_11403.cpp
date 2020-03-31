// <경로 찾기> - BOJ_11403
// 플로이드 와샬 알고리즘 - DP기반임

#include<bits/stdc++.h>
using namespace std;

int adjM[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>adjM[i][j];

    for(int x=0; x<n; x++){ // 거쳐가는 노드
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adjM[i][x] && adjM[x][j]) adjM[i][j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<adjM[i][j]<<' ';
        }
        cout<<'\n';
    }
}
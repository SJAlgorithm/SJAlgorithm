// <뮤탈리스크> - BOJ_12869
// DP
// if문 조금 줄여보려고 하다가 더 오래걸림 그냥 생각나는대로 코딩하기...!!!

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int N; // scv수 , 1<=N<=3
int life[3]={0,}; // 1<=life<=60
int dp[61][61][61]={0,};
int a,b,c;

void chk(int i, int j, int k, int d1, int d2, int d3){
    if(i-d1<0) a=0; else a=i-d1;
    if(j-d2<0) b=0; else b=j-d2;
    if(k-d3<0) c=0; else c=k-d3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<3; i++) cin>>life[i];
    
    for(int i=0; i<=life[0]; i++){
        for(int j=0; j<=life[1]; j++){
            for(int k=0; k<=life[2]; k++){
                int min_ = INF;
                chk(i,j,k,9,3,1);
                min_ = min(dp[a][b][c],min_);
                chk(i,j,k,9,1,3);
                min_ = min(dp[a][b][c],min_);
                chk(i,j,k,3,9,1);
                min_ = min(dp[a][b][c],min_);
                chk(i,j,k,3,1,9);
                min_ = min(dp[a][b][c],min_);
                chk(i,j,k,1,9,3);
                min_ = min(dp[a][b][c],min_);
                chk(i,j,k,1,3,9);
                min_ = min(dp[a][b][c],min_);

                dp[i][j][k] = min_+1;
            }
        }
    }
    cout<<dp[life[0]][life[1]][life[2]]-1;
}

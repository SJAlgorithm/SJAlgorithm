// <2048 (Easy)> - BOJ_12100
// 구현, DFS

#include<bits/stdc++.h>
using namespace std;
const int INF = -1;
int m[6][22][22]{};
int N,max_=0;

void solve2(int k, int d){ // direction ,depth
    memset(m[d+1],0,sizeof(m[d+1]));
    for(int i=1; i<=N; i++) {m[d+1][i][0]=m[d+1][i][N+1]=INF;}
    for(int j=1; j<=N; j++) {m[d+1][0][j]=m[d+1][N+1][j]=INF;}

    if(k==0){ // 상
        for(int j=1; j<=N; j++){
            int n=1;
            for(int i=1; i<=N; i++){
                if(m[d][i][j]==0) continue;
                for(int c=i+1; c<=N+1; c++){
                    if(m[d][c][j]==0) continue;
                    if(m[d][i][j]==m[d][c][j]) {
                        m[d+1][n++][j]=m[d][i][j]*2;
                        i=c;
                        break;
                    }
                    else{
                        m[d+1][n++][j]=m[d][i][j];
                        i=c-1;
                        break;
                    }
                }
            }
        }
    }
    else if(k==1){ // 하
        for(int j=1; j<=N; j++){
            int n=N;
            for(int i=N; i>=1; i--){
                if(m[d][i][j]==0) continue;
                for(int c=i-1; c>=0; c--){
                    if(m[d][c][j]==0) continue;
                    if(m[d][i][j]==m[d][c][j]) {
                        m[d+1][n--][j]=m[d][i][j]*2;
                        i=c;
                        break;
                    }
                    else{
                        m[d+1][n--][j]=m[d][i][j];
                        i=c+1;
                        break;
                    }
                }
            }
        }
    }
    else if(k==2){ // 좌
        for(int i=1; i<=N; i++){
            int n=1;
            for(int j=1; j<=N; j++){
                if(m[d][i][j]==0) continue;
                for(int c=j+1; c<=N+1; c++){
                    if(m[d][i][c]==0) continue;
                    if(m[d][i][j]==m[d][i][c]) {
                        m[d+1][i][n++]=m[d][i][j]*2;
                        j=c;
                        break;
                    }
                    else{
                        m[d+1][i][n++]=m[d][i][j];
                        j=c-1;
                        break;
                    }
                }
            }
        }
    }
    else{ // 우
        for(int i=1; i<=N; i++){
            int n=N;
            for(int j=N; j>=1; j--){
                if(m[d][i][j]==0) continue;
                for(int c=j-1; c>=0; c--){
                    if(m[d][i][c]==0) continue;
                    if(m[d][i][j]==m[d][i][c]) {
                        m[d+1][i][n--]=m[d][i][j]*2;
                        j=c;
                        break;
                    }
                    else{
                        m[d+1][i][n--]=m[d][i][j];
                        j=c+1;
                        break;
                    }
                }
            }
        }
    }
}

void solve(int depth){
    if(depth==5){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                max_ = max(m[depth][i][j],max_);
            }
        }
        return;
    }

    for(int i=0; i<4; i++){
        solve2(i,depth);
        solve(depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) {m[0][i][0]=m[0][i][N+1]=INF;}
    for(int j=1; j<=N; j++) {m[0][0][j]=m[0][N+1][j]=INF;}

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>m[0][i][j];
            max_ = max(m[0][i][j],max_);
        }
    }

    if(N==1) {cout<<max_; return 0;}
    solve(0);
    cout<<max_;
}
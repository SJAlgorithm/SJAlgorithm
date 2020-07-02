// <2048 (Hard)> - BOJ_12094
// DFS, 구현, 상수커팅(가지치기)

#include<bits/stdc++.h>
using namespace std;
const int INF = -1;
int m[11][22][22]{};
int N,max_=0;
int num[11][20]{};

bool chkMax(int d){
    int mc = d+1; // move count 남은 이동수
    int z = num[d][mc];
    for(int i=mc; i<max_; i++){
        z = z/2 + num[d][i+1];
    }
    if(z<2) return false;
    else return true;
}

bool solve2(int k, int d){ // direction ,depth
    memset(m[d+1],0,sizeof(m[d+1]));
    memset(num[d+1],0,sizeof(num[d+1]));
    for(int i=1; i<=N; i++) {m[d+1][i][0]=m[d+1][i][N+1]=INF;}
    for(int j=1; j<=N; j++) {m[d+1][0][j]=m[d+1][N+1][j]=INF;}

    if(k==0){ // 상
        for(int j=1; j<=N; j++){
            int n=1;
            for(int i=1; i<=N; i++){
                int nm = m[d][i][j];
                if(nm==0) continue;
                for(int c=i+1; c<=N+1; c++){
                    if(m[d][c][j]==0) continue;
                    if(nm==m[d][c][j]) {
                        m[d+1][n++][j]=nm+1;
                        num[d+1][nm+1]++;
                        i=c;
                        break;
                    }
                    else{
                        m[d+1][n++][j]=nm;
                        num[d+1][nm]++;
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
                int nm = m[d][i][j];
                if(nm==0) continue;
                for(int c=i-1; c>=0; c--){
                    if(m[d][c][j]==0) continue;
                    if(nm==m[d][c][j]) {
                        m[d+1][n--][j]=nm+1;
                        num[d+1][nm+1]++;
                        i=c;
                        break;
                    }
                    else{
                        m[d+1][n--][j]=nm;
                        num[d+1][nm]++;
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
                int nm = m[d][i][j];
                if(nm==0) continue;
                for(int c=j+1; c<=N+1; c++){
                    if(m[d][i][c]==0) continue;
                    if(nm==m[d][i][c]) {
                        m[d+1][i][n++]=nm+1;
                        num[d+1][nm+1]++;
                        j=c;
                        break;
                    }
                    else{
                        m[d+1][i][n++]=nm;
                        num[d+1][nm]++;
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
                int nm = m[d][i][j];
                if(nm==0) continue;
                for(int c=j-1; c>=0; c--){
                    if(m[d][i][c]==0) continue;
                    if(nm==m[d][i][c]) {
                        m[d+1][i][n--]=nm+1;
                        num[d+1][nm+1]++;
                        j=c;
                        break;
                    }
                    else{
                        m[d+1][i][n--]=nm;
                        num[d+1][nm]++;
                        j=c+1;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(m[d][i][j]!=m[d+1][i][j]){
                return true;
            }
        }
    }
    return false;
}

void solve(int depth){
    if(!chkMax(0)) {cout<<(1<<max_); exit(0);}
    if(depth==10) return;

    for(int i=0; i<4; i++){
        bool flag = false;
        if(!solve2(i,depth)) continue;
        for(int i=19; i>max_; i--){
            if(num[depth+1][i]){
                max_ = i;
                break;
            }
        }
        solve(depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) {m[0][i][0]=m[0][i][N+1]=INF;}
    for(int j=1; j<=N; j++) {m[0][0][j]=m[0][N+1][j]=INF;}
    int t;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>t;
            if(t==2) t=1;
            else if(t==4) t=2;
            else if(t==8) t=3;
            else if(t==16) t=4;
            else if(t==32) t=5;
            else if(t==64) t=6;
            else if(t==128) t=7;
            else if(t==256) t=8;
            else if(t==512) t=9;
            else if(t==1024) t=10;
            m[0][i][j] = t;
            num[0][t]++;
            max_ = max(m[0][i][j],max_);
        }
    }
    
    if(N==1) {cout<<(1<<max_); return 0;}
    solve(0);
    cout<<(1<<max_);
}
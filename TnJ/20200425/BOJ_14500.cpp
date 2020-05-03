
// <테트로미노> - BOJ_14500
// 단순 브르트포스가 더빠르지만 귀찮아서 DFS돌림.

#include<bits/stdc++.h>
using namespace std;

int N,M;// 4<= N,M<=500
int tMap[501][501]={0,};
int vi[501][501]={0,};
int max_ = 0, sum=0;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void dfs(int depth, int y, int x){
    if(depth == 3){
        max_ = sum>max_ ? sum : max_;
        return;
    }
    
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
        if(!vi[ny][nx]){
            vi[ny][nx] = true;
            sum+=tMap[ny][nx];
            dfs(depth+1,ny,nx);
            vi[ny][nx] = false;
            sum-=tMap[ny][nx];
        }
    }
}

void checkH(int y, int x){
    int sum_;
    if(y-1>=0 && x-1>=0 && x+1<M){// h
        sum_ = tMap[y][x] + tMap[y-1][x] + tMap[y][x-1] + tMap[y][x+1];
        max_ = sum_>max_ ? sum_ : max_;
    }
    if(y+1<N && x-1>=0 && x+1<M){// n
        sum_ = tMap[y][x] + tMap[y+1][x] + tMap[y][x-1]+ tMap[y][x+1];
        max_ = sum_>max_ ? sum_ : max_;
    }
    if(x-1>=0 && y-1>=0 && y+1<N){// j
        sum_ = tMap[y][x] + tMap[y][x-1] + tMap[y-1][x]+ tMap[y+1][x];
        max_ = sum_>max_ ? sum_ : max_;
    }
    if(x+1<M && y-1>=0 && y+1<N){// k
        sum_ = tMap[y][x] + tMap[y][x+1] + tMap[y-1][x]+ tMap[y+1][x];
        max_ = sum_>max_ ? sum_ : max_;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>tMap[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            vi[i][j] = true;
            sum+=tMap[i][j];
            dfs(0,i,j);
            vi[i][j] = false;
            sum-=tMap[i][j];
            checkH(i,j);
        }
    }

    cout<<max_;
}
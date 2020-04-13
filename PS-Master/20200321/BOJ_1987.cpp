// <알파벳> - BOJ_1987
// DFS를 이용한 백트래킹

#include<bits/stdc++.h>
using namespace std;

int r,c;
int maxC=1,cnt=0;
// up, down, left, right
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
char v[21][21] = {0,};
bool vi[26] = {false,};


void dfs(int y, int x){
    vi[v[y][x]-'A'] = true;
    cnt++;
    if(cnt > maxC) maxC = cnt;
    
    for(int i=0; i<4; i++) {
        int b = y+dy[i];
        int a = x+dx[i];
        if((b<0 || b>=r) || (a<0 || a>=c)) continue;
        if(!vi[v[b][a]-'A']){
            dfs(b,a);
            vi[v[b][a]-'A']=false;
            cnt--;
        }   
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++){
            cin>>v[i][j];
        }
    }

    dfs(0,0);
    cout<<maxC;
}
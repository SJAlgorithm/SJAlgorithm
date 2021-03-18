#include<bits/stdc++.h>
using namespace std;

int R,C,T;
int m1[51][51]{} , m2[51][51]{};
bool vi[51][51]{};
int air[2][2]{};

int dy1[4] = {0,-1,0,1}; // 위 
int dx1[4] = {1,0,-1,0};
int dy2[4] = {0,1,0,-1}; // 아래
int dx2[4] = {1,0,-1,0};

void expand(){
    memset(m2,0,sizeof(m2));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(m1[i][j]<1) continue;
            int sum=0;
            for(int k=0; k<4; k++){
                int ny = i + dy1[k];
                int nx = j + dx2[k];
                if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
                if(m1[ny][nx]==-1) continue;
                int nd = m1[i][j]/5;
                m2[ny][nx] += nd;
                sum += nd;
            }
            m2[i][j] += (m1[i][j]-sum);
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(m1[i][j]==-1) continue;
            m1[i][j] = m2[i][j];
        }
    }
}

void work(){
    int dir = 0, pre = 0;
    int cy = air[0][0];
    int cx = air[0][1];
    while(1){
        int ny = cy + dy1[dir];
        int nx = cx + dx1[dir];
        if(ny<0 || nx<0 || ny>=R || nx>=C) {dir++; continue;}
        if(m1[ny][nx]==-1) break;
        int tmp = m1[ny][nx];
        m1[ny][nx] = pre;
        pre = tmp;
        cy = ny;
        cx = nx;
    }

    dir = 0, pre = 0;
    cy = air[1][0];
    cx = air[1][1];
    while(1){
        int ny = cy + dy2[dir];
        int nx = cx + dx2[dir];
        if(ny<0 || nx<0 || ny>=R || nx>=C) {dir++; continue;}
        if(m1[ny][nx]==-1) break;
        int tmp = m1[ny][nx];
        m1[ny][nx] = pre;
        pre = tmp;
        cy = ny;
        cx = nx;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C>>T; // T초
    int t=0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>m1[i][j];
            if(m1[i][j]==-1){
                air[t][0] = i;
                air[t][1] = j;
                t++;
            }
        }
    }

    while(T--){
        expand();
        work();
    }

    int sum=0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(m1[i][j]<1) continue;
            sum += m1[i][j];
        }
    }

    cout<<sum;
}
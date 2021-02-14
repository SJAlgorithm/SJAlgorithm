#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int R,C;
char m[51][51]{};
vector<pii> w;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void water(){
    vector<pii> nw;
    for(auto v : w){
        for(int i=0; i<4; i++){
            int ny = v.xx + dy[i];
            int nx = v.yy + dx[i];
            if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
            if(m[ny][nx]=='D' || m[ny][nx]=='*' || m[ny][nx] == 'X') continue;
            nw.push_back({ny,nx});
            m[ny][nx] = '*';
        }
    }

    w = nw;
}

bool vi[51][51]{};
string bfs(int sty, int stx, int edy, int edx){
    queue<piii> q;
    q.push({0,{sty,stx}});
    vi[sty][stx] = true;

    while(!q.empty()){
        queue<piii> nq;
        water();
        int qsz=q.size();
        for(int k=0; k<qsz; k++){
            int cd = q.front().xx;
            int cy = q.front().yy.xx;
            int cx = q.front().yy.yy;
            q.pop();

            if(cy == edy && cx == edx) return to_string(cd);

            for(int i=0; i<4; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
                if(vi[ny][nx] || m[ny][nx]=='*' || m[ny][nx] == 'X') continue;
                nq.push({cd+1,{ny,nx}});
                vi[ny][nx] = true;
            }
        }
        q = nq;
    }
    
    return "KAKTUS";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    string str;
    int sty, stx, edy, edx;
    for(int i=0; i<R; i++){
        cin>>str;
        for(int j=0; j<C; j++){
            m[i][j] = str[j];
            if(m[i][j] == 'S') sty = i, stx = j;
            else if(m[i][j] == 'D') edy = i, edx = j;
            else if(m[i][j] == '*') w.push_back({i,j});
        }
    }

    cout<<bfs(sty, stx, edy, edx);
}
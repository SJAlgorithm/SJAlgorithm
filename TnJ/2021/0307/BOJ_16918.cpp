#include<bits/stdc++.h>
using namespace std;

int R,C,N;
bool m[201][201]{};
bool t[201][201]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C>>N;
    if(N%2==0){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout<<'O';
            }
            cout<<'\n';
        }
        return 0;
    }

    string str;
    for(int i=0; i<R; i++){
        cin>>str;
        for(int j=0; j<C; j++){
            if(str[j]=='.') m[i][j] = false;
            else m[i][j] = true;
        }
    }

    N /= 2;
    while(N--){
        memset(t,0,sizeof(t));
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(m[i][j]==0) continue;
                t[i][j] = true;
                for(int k=0; k<4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
                    t[ny][nx] = true;
                }
            }
        }
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(t[i][j]) m[i][j] = false;
                else m[i][j] = true;
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(m[i][j]==true) cout<<'O';
            else cout<<'.';
        }
        cout<<'\n';
    }
    
}
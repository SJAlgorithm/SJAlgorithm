#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N;
int m[50001][2]{};
bool vi[50001]{};

int f(int xy, int t, int &chk){ // xy 일때
    if(vi[t]) return 0;
    if(chk==-1) {
        chk = m[t][xy];
        vi[t] = true;
        return 1;
    }
    if(chk == m[t][xy]) {
        vi[t] = true;
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int a,b;
    for(int i=0; i<N; i++) {
        cin>>m[i][0]>>m[i][1];
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                memset(vi,0,sizeof(vi));
                int cnt = 0;
                int chk=-1;
                for(int t=0; t<N; t++){
                    cnt += f(i, t, chk);
                    if(cnt==N) {cout<<1; return 0;}
                }

                chk = -1;
                for(int t=0; t<N; t++){
                    cnt += f(j, t, chk);
                    if(cnt==N) {cout<<1; return 0;}
                }

                chk = -1;
                for(int t=0; t<N; t++){
                    cnt += f(k, t, chk);
                    if(cnt==N) {cout<<1; return 0;}
                }
            }
        }
    }
    cout<<0;
}
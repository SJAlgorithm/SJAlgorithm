// <텀 프로젝트> - BOJ_9466
// DFS, Cycle 찾기

#include<bits/stdc++.h>
using namespace std;

int T,N;
int v[100001]{};
int c[100001]{};
vector<int> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        memset(c,0,sizeof(c));
        st.clear();
        cin>>N;
        int cyc = 1;
        for(int i=1; i<=N; i++){
            cin>>v[i];
            if(v[i]==i) c[i]=cyc++;
        }
        for(int i=1; i<=N; i++){
            if(c[i]) continue;
            st.clear();
            int t=i;
            for(int j=1; j<=N-cyc+1; j++) {
                if(c[v[t]]) {
                    c[t] = -1;
                    for(auto val : st){
                        c[val] = -1;
                    }
                    break;
                }
                else {
                    if(v[t]==i){
                        c[t] = cyc;
                        for(auto val : st){
                            c[val] = cyc;
                        }
                        cyc++;
                        break;
                    }
                    st.push_back(t);
                    t = v[t];
                }
            }
        }
        int cnt2=0;
        for(int i=1; i<=N; i++){
            if(c[i]==0 || c[i]==-1) cnt2++;
        }
        cout<<cnt2<<'\n';
    }

}

/*
1 2 3 4 5 6 7
3 1 3 7 3 4 6

행렬A
0 0 1 0 0 0 0
1 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 0 1 0
A^2 = 중간에 다른곳을 한번 거쳐서 갈수있는경우

A^3                A^4
1 0 1  1 0 1  =  1 0 2
0 1 1  0 1 1  =  .....
0 0 1  0 0 5  =  .....
*/

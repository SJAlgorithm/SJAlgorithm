// <파티> - BOJ_1238
// 플로이드 와샬 풀이

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int m[1001][1001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(m,0x3f,sizeof(m));
    int N,M,X;
    cin>>N>>M>>X;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        m[a][b] = min(c,m[a][b]);
    }
    
    for(int i=1; i<=N; i++) m[i][i] = 0;
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            if(m[i][k]==INF || i==k) continue;
            for(int j=1; j<=N; j++){
                if(m[i][j] > m[i][k] + m[k][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }

    int max_=0;
    for(int i=1; i<=N; i++){
        max_ = max(m[i][X]+m[X][i], max_);
    }
    cout<<max_;
}
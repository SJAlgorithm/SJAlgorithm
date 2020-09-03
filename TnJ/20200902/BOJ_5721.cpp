#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long ll;

ll m[100010]{};
ll dp1[100010]{};
ll dp2[100010]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N=1,M=1;
    while(N!=0 && M!=0){
        cin>>N>>M;
        if(!N&&!M) break;
        memset(m,0,sizeof(m));
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));

        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++) cin>>m[j];
            dp1[1] =  m[1];
            if(M>1) dp1[2] = m[2];
            for(int j=1; j<=M; j++) dp1[j] = max(dp1[j-1],dp1[j-2]+m[j]);
            dp2[i] = dp1[M];
        }
        dp1[1] = dp2[1];
        if(N>1) dp1[2] = dp2[2];
        for(int i=1; i<=N; i++){
            dp1[i] = max(dp1[i-1],dp1[i-2]+dp2[i]);
        }
        cout<<dp1[N]<<'\n';
    }

}
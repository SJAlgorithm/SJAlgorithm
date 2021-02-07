#include<bits/stdc++.h>
using namespace std;
int m[100001]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>m[i];
    }
    if(N==1) {cout<<1; return 0;}

    int ans=0, len=1;
    for(int i=1; i<N; i++){
        if(m[i-1]<=m[i]) {len++; ans=max(ans, len);}
        else len = 1;
    }
    
    len = 1;
    for(int i=1; i<N; i++){
        if(m[i-1]>=m[i]) {len++; ans=max(ans, len);}
        else len = 1;
    }

    cout<<ans;
}
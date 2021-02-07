#include<bits/stdc++.h>
using namespace std;

int m[100002]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=1; i<=N; i++) cin>>m[i];
    if(m[N]<=0) {cout<<m[N-1] + m[N]; return 0;}
    if(m[1]>=0) {cout<<m[1] + m[2]; return 0;}

    int ans=1e9, l=1, r=N;
    while(l!=r){
        int s = m[l] + m[r];
        if(abs(s) < abs(ans)) ans = s;
        if(s<0) l++;    
        else if(s>0) r--;
        else {cout<<0; return 0;}
    }
    cout<<ans;
}

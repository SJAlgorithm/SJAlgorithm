#include<bits/stdc++.h>
using namespace std;

int N;
int sla[101]={0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) cin>>sla[i];
    
    int sum=0;
    int t=sla[0];
    for(int i=1; i<N; i++){
        sum+=(t*sla[i]);
        t+=sla[i];
    }
    cout<<sum;
}
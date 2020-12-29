#include<bits/stdc++.h>
using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    long long i=1;
    long long cnt=-1;
    while(N>=0){
        N-=i;
        i++;
        cnt++;
    }
    cout<<cnt;
}
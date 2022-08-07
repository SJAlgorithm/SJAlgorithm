#include<bits/stdc++.h>
using namespace std;

int N;
int m[500001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; 
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];
    sort(m, m+N);

    int now = N/2;
    int res = 0;
    for(int i=0; i<N/2; i++){
        int t = lower_bound(m, m+N, m[i]*2) - m;
        if(t==N) break;
        if(t <= now) {
            now++;
            res++;
        } else {
            now = t+1;
            res++;
        }
        if(now == N) break;
    }

    cout<<N-res;
}
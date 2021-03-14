#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;

int N;
map<int,int> res;
int m[500001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; 
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];
    sort(m, m+N);
    for(int i=0; i<N; i++){
        int t = lower_bound(m, m+N, m[i]*2) - m;
        t = N-t;
        if(!t) continue;
        res[t]++;
    }
    int tmp = 0, prev = 0;
    for(auto val : res) {
        int now = val.xx - prev;
        int num = val.yy;
        if(now < num) {
            tmp += now;
            prev += now;
        }
        else {
            tmp += num;
            prev += num;
        }
        if(tmp > N/2) {tmp = N/2; break;}
    }

    cout<<N-tmp;
}
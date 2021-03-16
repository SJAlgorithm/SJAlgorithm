#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX_N 1000
using namespace std;
typedef pair<int,int> pii;

int N;
pii m[MAX_N+1]{};
int score[MAX_N+1]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int max_=0;
    for(int i=0; i<N; i++) {
        cin>>m[i].xx>>m[i].yy;
        max_ = max(max_, m[i].xx);
    }
    sort(m,m+N, [&](pii x, pii y) -> bool{
        if(x.yy == y.yy) return x.xx < y.xx;
        return x.yy > y.yy;
    });

    for(int i=0; i<N; i++) {
        int d = m[i].xx;
        if (!score[d]) {
            score[d] = m[i].yy;
            continue;
        }
        while(--d){
            if(!score[d]) {
                score[d] = m[i].yy;
                break;
            }
        }
    }

    int ans=0;
    for (int i=1; i<=max_; i++) ans += score[i];
    cout << ans;
}
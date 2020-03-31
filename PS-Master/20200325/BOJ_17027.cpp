// <shell game> - BOJ_17027
// 단순구현(시뮬레이션)

#include<bits/stdc++.h>
using namespace std;
int pebble[4]={0,1,2,3}; // index : pebble 초기 위치
int point[4]={0,};
int a,b,g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;

    while(n--){
        cin>>a>>b>>g;
        for(int i=1; i<=3; i++){
            if(pebble[i]==a || pebble[i]==b)
                pebble[i] = (pebble[i]==a) ? b : a;
            if(g==pebble[i]) point[i]++;
        }
    }
    int res = max(max(point[1],point[2]),point[3]);
    cout<<res;
}
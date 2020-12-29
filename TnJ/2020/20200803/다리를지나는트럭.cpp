#include<bits/stdc++.h>
using namespace std;

int solution(int bl, int w, vector<int> tw) {
    int sz = tw.size();
    int ans = 1;
    vector<int> trPos(sz);
    int st=0;
    int ed=0;
    int wsum=tw[0];
    trPos[0]=1;
    while(st<sz){
        for(int i=st; i<=ed; i++){
            trPos[i]++;
        }
        if(trPos[st]>bl){
            wsum -= tw[st];
            st++;
        }
        if(ed+1<sz && wsum + tw[ed+1]<=w){
            ed++;
            wsum += tw[ed];
            trPos[ed] = 1;
        }
        ans++;
    }
    return ans;
}
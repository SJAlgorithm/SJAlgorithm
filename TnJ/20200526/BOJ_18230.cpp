// <2xN 예쁜 타일링> - BOJ_18230
// Greedy

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define rep(i,x,n) for(int i=x; i<n; i++)
#define aa first
#define bb second
#define all(v) (v).begin(), (v).end()

int N,A,B;
vector<int> am;
vector<int> bm;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>A>>B;
    int k;
    rep(i,0,A) {cin>>k; am.push_back(k);}
    rep(i,0,B) {cin>>k; bm.push_back(k);}
    sort(all(am));
    sort(all(bm));

    int res=0;
    if(N%2) {
        res+= am.back();
        am.pop_back();
        N--;
    }
    
    int i,j;
    while(N){
        i = am.size();
        j = bm.size();
        int asc,bsc;
        asc=bsc=0;
        if(i>1) asc = am[i-1]+am[i-2];
        if(j) bsc = bm[j-1];
        if(asc>bsc){
            res+=asc;
            am.pop_back(); am.pop_back();
        } else {
            res+=bsc;
            bm.pop_back();
        }
        N-=2;
    }
    cout<<res;
}
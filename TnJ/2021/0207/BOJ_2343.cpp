#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[100001]{};

bool ispossible(int mid){
    int cnt = 0, sum=0;
    for(int i=0; i<N; i++){
        if(sum+m[i] <= mid) sum+=m[i];
        else {cnt++; sum=m[i];}
    }
    if(sum!=0) cnt++;
    if(cnt > M) return true;
    else return false;
}

int paraSearch(int l, int r) {
    int s = l, e = r, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (ispossible(mid)) s = mid + 1;
        else                 e = mid - 1;
    }
    return e+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int sum=0, max_=0;
    for(int i=0; i<N; i++) {
        cin>>m[i];
        sum+=m[i];
        max_ = max(max_, m[i]);
    }

    cout<<paraSearch(max(sum/M,max_),sum);
}
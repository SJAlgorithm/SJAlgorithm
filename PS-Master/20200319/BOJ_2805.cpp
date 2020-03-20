// <나무자르기>

#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
vector<int> t;

long long b_search(long long start, long long end) { // reversed index
    long long sum=0;
    long long mid = (start+end)/2;
    for(int i=0; i<n; i++) {
        long long diff = t[i];
        diff -= mid;
        if(diff<=0) break;
        sum += diff;
    }
    
    if(sum == m) {
        return mid;
    } else if(sum > m) {
        if(mid+1> start) return mid;
        return b_search(start,mid+1);
    } else { // sum < m
        if(mid-1 < end) return mid-1;
        return b_search(mid-1,end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        int h; cin>>h;
        t.push_back(h);
    }
    sort(t.begin(), t.end(),greater<int>());

    long long ans = b_search(t[0]-1,0);
    cout<<ans;
}

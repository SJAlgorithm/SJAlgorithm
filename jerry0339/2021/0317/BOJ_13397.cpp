#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[5001]{};

bool isP(int mid){
    int res = 0, minN = m[0], maxN = m[0];
    for(int i=1; i<N; i++){
        if(m[i]<minN){
            if(maxN - m[i] > mid){
                minN = m[i];
                maxN = m[i];
                res++;
            } else {
                minN = m[i];
            }
        } else if(m[i]>maxN){
            if(m[i] - minN > mid){
                minN = m[i];
                maxN = m[i];
                res++;
            } else {
                maxN = m[i];
            }
        }
    }

    if(res<M) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>m[i];
    
    int s=0, e = *max_element(m,m+N);
    while(s<=e){
        int mid = (s+e)/2;
        if(isP(mid)) e = mid - 1;
        else s = mid + 1;
    }

    cout<<s;
}
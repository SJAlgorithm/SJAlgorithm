#include<bits/stdc++.h>
using namespace std;

int m[1000001]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,n;
    while(cin>>x){
        x *= 10000000;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>m[i];
        }
        if(n<2) {
            cout<<"danger"<<'\n';
            continue;
        }
        sort(m,m+n);
        int l=0, r=n-1, s, flag=0;
        while(l!=r){
            s = m[l]+m[r];
            if(s<x) l++;
            else if(s>x) r--;
            else {
                cout<<"yes "<<m[l]<<' '<<m[r]<<'\n';
                flag = 1;
                break;
            }
        }
        if(!flag) cout<<"danger"<<'\n';
    }
}
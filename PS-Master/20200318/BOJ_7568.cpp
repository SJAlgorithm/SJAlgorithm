// <덩치>

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y; // 몸무게, 키 : x,y
    int a,b;
    vector<pair<int,int>> v;
    cin>>n;
    vector<int> rank(n,1);
    for(int i=0; i<n; i++) {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            if(j==i)continue;
            if((v[i].first < v[j].first) && (v[i].second < v[j].second)) rank[i]++;
        }
    }

    for(int i=0; i<n; i++) cout<<rank[i]<<' ';
    
}
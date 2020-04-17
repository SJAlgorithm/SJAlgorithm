// <나는야 포켓몬 마스터 이다솜>

#include<bits/stdc++.h>
using namespace std;

string pok[100001]={"",};
vector<pair<string,int>> v;

int b_Search(int start, int end, string name){
    int mid = (start+end)/2;
    if(v[mid].first==name){
        return v[mid].second;
    } else if(v[mid].first > name) {
        return b_Search(start,mid,name);
    } else { // v[mid].first > name
        return b_Search(mid+1,end,name);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;

    for(int i=0; i<n; i++) {
        string name; cin>>name;
        pok[i] = name;
        v.push_back(make_pair(name,i+1));
    }
    sort(v.begin(),v.end());

    for(int i=0; i<m; i++){
        string input; cin>>input;
        int chk = atoi(input.c_str());
        if(chk) {
            cout<<pok[chk-1]<<'\n';
        } else {
            cout<<b_Search(0,n,input)<<'\n';
        }
    }
}
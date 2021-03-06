#include<bits/stdc++.h>
using namespace std;

int N,M;
int parent[52]{};
vector<int> party[52];

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<=51; i++) parent[i] = i;

    int k,a;
    cin>>k;
    while(k--) {
        cin>>a;
        merge(51,a);
    }
    
    for(int i=0; i<M; i++){
        cin>>k;
        while(k--) {
            cin>>a;
            party[i].push_back(a);
        }

        for(int j=1; j<party[i].size(); j++){
            merge(party[i][j-1], party[i][j]);
        }
    }
    
    int ans = 0;
    for(int i=0; i<M; i++) {
        bool chk = true;
        for(int j=0; j<party[i].size(); j++){
            if(find(51) == find(party[i][j])) {
                chk = false;
                break;
            }
        }
        if(chk) ans++;
    }
    cout<<ans;
}


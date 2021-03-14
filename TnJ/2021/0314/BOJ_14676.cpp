#include<bits/stdc++.h>
using namespace std;

int N,M,K;
vector<int> adj[100001]{};
int deg[100001]{};
int num[100001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }

    for(int i=0; i<K; i++){
        cin>>a>>b;
        if(a==1){
            if(deg[b]) {cout<<"Lier!"; return 0; }
            if(++num[b] > 1) continue;
            for(auto val : adj[b]){
                deg[val]--;
            }
        } else {
            if(!num[b]) {cout<<"Lier!"; return 0; }
            if(--num[b] > 0) continue;
            for(auto val : adj[b]){
                deg[val]++;
            }
        }
    }

    cout<<"King-God-Emperor";
}
#include<bits/stdc++.h>
using namespace std;

int N,K;
int deg[100001]{};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N;
    int a,b;
    for(int i=0; i<N-1; i++) {
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }

    cin>>K;
    while(K--){
        cin>>a>>b;
        if(a==1) {
            if(deg[b]==1)
                cout<<"no"<<'\n';
            else
                cout<<"yes"<<'\n';
        } else cout<<"yes"<<'\n';
    }
    
}
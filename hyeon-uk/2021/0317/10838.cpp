#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int n,k;
int parent[100010];
int lca[100010];
int cost[100010];

int LCA(int a,int b,int i){
    if(a==b) return a;
    int cnt=0;
    while(a&&cnt<1000){
        lca[a]=i;
        a=parent[a];
        cnt++;
    }
    cnt=0;
    while(b&&cnt<1000){
        if(lca[b]==i) return b;
        b=parent[b];
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    parent[0]=-1;
    
    int r,a,b,c;
    for(int i=1;i<=k;i++){
        cin>>r>>a>>b;
        //paint
        if(r==1){
            cin>>c;
            int l=LCA(a,b,i);
            while(a!=l){
                cost[a]=c;
                a=parent[a];
            }
            while(b!=l){
                cost[b]=c;
                b=parent[b];
            }
        }
        //move
        else if(r==2){
            parent[a]=b;
        }
        //count
        else{
            set<int> s;
            int l=LCA(a,b,i);
            while(a!=l){
                s.insert(cost[a]);
                a=parent[a];
            }
            while(b!=l){
                s.insert(cost[b]);
                b=parent[b];
            }
            cout<<s.size()<<"\n";
        }
    }
    return 0;
}
#include <algorithm>
#include<iostream>
#include<map>

using namespace std;

int N,K,Q;
long long a[1000001]={0};
long long s[1000001]={0};
map<int,int> X;
void something(int jump,int cnt){
    int i=0;
    while(i<N){
        a[i]=a[i]+cnt;
        i=i+jump;
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int x;
        cin>>x;
        X[x]++;
    }
    
    for(auto x:X){
        int jump=x.first;
        int cnt=x.second;
        something(jump,cnt);
    }
    
    
    s[0]=a[0];
    
    for(int i=1;i<N;i++){
        s[i]=s[i-1]+a[i];
    }
    
    cin>>Q;
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<"\n";
    }
}
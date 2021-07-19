#include <algorithm>
#include<iostream>

using namespace std;


int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n;
    int cnt5=0;
    int cnt3=0;
    cin>>n;
    cnt5=n/5;
    n%=5;
    
    while(true){
        if(n==0) break;
        
        cnt3+=n/3;
        n%=3;
        
        if(cnt5==0) break;
        
        if(n!=0){
            cnt5--;
            n+=5;
        }
    }
    if(n!=0){
        cout<<-1;
    }
    else{
        cout<<cnt5+cnt3;
    }
}
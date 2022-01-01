#include<iostream>
using namespace std;
int arr[30];

int solve(int n){
    if(n%2==1) return 1;
    int odd=0,even=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            if(i%2==1) odd++;
            else even++;
        }
    }
    if(-1<= (even-odd) && (even-odd)<=1) return 1;
    return 0;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        if(solve(n)==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
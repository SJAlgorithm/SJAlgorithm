// <분해합>

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k=1; cin>>n;
    
    for(int i=n/2; i<n; i++){
        int temp = i;
        int sum=0;
        while(temp){
            sum += (temp%10);
            temp /= 10;
        }

        if((sum+i)==n) {
            cout<<i;
            return 0;
        }
    }
    cout<<'0';
}
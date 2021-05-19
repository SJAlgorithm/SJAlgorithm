#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100001]={0};
int dp[100001]={0};
int sz=0;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sq=0;
    for(int i=0;i<n;i++){
        if(sq>0){
            if(arr[i]==arr[i-1]){
                dp[sz++]=sq;
                sq=0;
            }
        }
        
        sq++;
    }
    
    if(sq>0){
        dp[sz++]=sq;
    }
    
    
    int mx=0,now=0;
    
    for(int i=0;i<sz;i++){
        now+=dp[i];
        if(i>=3){
            now-=dp[i-3];
        }
        mx=max(mx,now);
    }
    
    cout<<mx;
	return 0;
}

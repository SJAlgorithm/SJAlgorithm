#include <algorithm>
#include<iostream>
#include<cmath>
using namespace std;

int n;
int arr[100010];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int left=0;
    int right=n-1;
    int min=987654321;
    int result=-1;
    while(left<right){
        int s=arr[right]+arr[left];
        if(abs(s)<min){
            min=abs(s);
            result=s;
        }
        
       if(s>0){
           right--;
       }
       else{
           left++;
       }
    }
    cout<<result;
}

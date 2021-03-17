#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
int arr[5000];

int ch(int middle){
    int minimum=arr[0];
    int maximum=arr[0];
    int cnt=1;
    
    for(int i=1;i<n;i++){
        minimum=min(arr[i],minimum);
        maximum=max(arr[i],maximum);
        
        if(maximum-minimum>middle){
            minimum=maximum=arr[i];
            cnt++;
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int left=0,right=10000;
    //최솟값에 따른 이분탐색
    //임의의 최솟값 기준 구간이 m보다 많이 나오면 left갱신
    //아니면 right갱신
    while(left<=right){
        int middle=(left+right)/2;
        
        if(ch(middle)>m){
            left=middle+1;
        }
        else{
            right=middle-1;
        }
    }
    cout<<left<<"\n";
}
#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,middle;
        priority_queue<int> left,right;
        
        cin>>n;
        cout<<(n+1)/2<<"\n";
        for(int i=1;i<=n;i++){
            int data;
            cin>>data;
            
            if(i==1){
                middle=data;
            }
            else{
                if(data>middle){
                    right.push(-data);
                }
                else{
                    left.push(data);
                }
            }
            
            if(i%2==1){
                if(left.size()<right.size()){
                    left.push(middle);
                }
                else{
                    right.push(-middle);
                }
                
                if(left.size()<right.size()){
                    middle=-right.top();
                    right.pop();
                }
                else{
                    middle=left.top();
                    left.pop();
                }
                
                cout<<middle<<" ";
                if(i%10==0) cout<<"\n";
            }
        }
        cout<<"\n";
    }
   
}
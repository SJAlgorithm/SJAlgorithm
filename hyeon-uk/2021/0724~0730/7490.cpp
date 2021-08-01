#include <algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

void dfs(int now,string st_now,int n){
    if(now==n){
        int sum=0;
        char sign='+';
        int temp=0;
        for(int i=0;i<st_now.size();i++){
            if(st_now[i]>='0'&&st_now[i]<='9'){
                temp=temp*10+(st_now[i]-'0');
                if(i==st_now.size()-1){
                    if(sign=='+'){
                        sum+=temp;
                    }
                    else{
                        sum-=temp;
                    }
                }
            }
            else if(st_now[i]=='+'||st_now[i]=='-'){
                if(sign=='+'){
                    sum+=temp;
                }
                else{
                    sum-=temp;
                }
                temp=0;
                sign=st_now[i];
                
            }
        }
        if(sum==0){
            cout<<st_now<<"\n";
        }
        return;
    }
    
    dfs(now+1,st_now+" "+to_string(now+1),n);
    dfs(now+1,st_now+"+"+to_string(now+1),n);
    dfs(now+1,st_now+"-"+to_string(now+1),n);
    
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        dfs(1,"1",n);
        cout<<"\n";
    }
}

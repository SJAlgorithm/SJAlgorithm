#include <algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> v;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string st;
        cin>>st;
        v.push_back(st);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(v[i].size()==v[j].size()){
                bool flag=true;
                int sz=v[i].size();
                for(int k=0;k<sz;k++){
                    if(v[i][k]!=v[j][sz-1-k]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cout<<sz<<" " <<v[i][sz/2];
                }
            }
        }
    }
}
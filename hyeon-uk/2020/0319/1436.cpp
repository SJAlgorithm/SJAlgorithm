#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    int cnt=0;
    string s;
    int title=665;
    cin>>n;
    while(++title){
        s=to_string(title);
        if(s.find("666")!=-1){
            cnt++;
        }
        if(cnt==n){
            cout<<s<<endl;
            break;
        }
    }
}
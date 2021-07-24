#include <algorithm>
#include<iostream>
#include<string>

using namespace std;


bool isRight(string str){
    for(int i=0;i<str.size()/2;i++){
        if(str[i]!=str[str.size()-1-i]){
            return false;
        }
    }
    return true;
}

int stringToInt(string str){
    return stoi(str);
}

string intToString(int n){
    string temp=to_string(n);
    while(temp.size()<str.size()){
        temp="0"+temp;
    }
    return temp;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    while(true){
        string str;
        cin>>str;
        if(str=="0") break;
        
        int cnt=0;
        while(!isRight(str)){
            cnt++;
            int temp=stringToInt(str);
            temp++;
            str=intToString(temp);
        }
        cout<<cnt<<"\n";
    }

}

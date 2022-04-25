#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N;
vector<string> vec;

bool cmp(string s1, string s2){
    if(s1.length() < s2.length()){
        return true;
    }else if(s1.length() == s2.length()){ 
         return s1<s2;
        
    }else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    while(N--){
        string s;
        cin >> s;
        vec.push_back(s);
    }
    
    sort(vec.begin(), vec.end(), cmp);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());


    
    for(string s : vec){
        cout << s << "\n";
    }
}
#include <algorithm>
#include<iostream>
#include<string>
using namespace std;

string str;
int len;
int max_N;
bool visited[51]={0};
vector<int> result;

bool dfs(int index){
    if(index==len){
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return true;   
    }
    
    string temp="";
    int single_digit,double_digit;
    temp+=str[index];
    single_digit=stoi(temp);

    if(single_digit<=max_N&&!visited[single_digit]){
        result.push_back(single_digit);
        visited[single_digit]=true;
        if(dfs(index+1)) return true;
        visited[single_digit]=false;
        result.pop_back();
    }
    
    temp+=str[index+1];
    double_digit=stoi(temp);
    if(double_digit<=max_N&&!visited[double_digit]){
        result.push_back(double_digit);
        visited[double_digit]=true;
        if(dfs(index+2)) return true;
        visited[double_digit]=false;
        result.pop_back();
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin>>str;
    len=str.size();
    
    if(len<10){
        max_N=len;
    }
    else{
        max_N=(len-9)/2 + 9;
    }
    
    dfs(0);
}
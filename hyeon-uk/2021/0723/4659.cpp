#include <algorithm>
#include<iostream>
#include<string>
using namespace std;

bool isVowels(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
        return true;
    }
    else{
        return false;
    }
}

bool isAcceptable(string st){
    int vowels=0;
    int sequenceV=0;
    int sequenceC=0;
        
    for(int i=0;i<st.size();i++){
        //모음의 개수를 세어주고 , 모음이 연속 3개면 false
        if(isVowels(st[i])){
            vowels++;
            sequenceV++;
            sequenceC=0;
            if(sequenceV==3){
                return false;
            }
        }
        //자음의 개수를 세어주고, 자음이 연속 3개면 false
        else{
            sequenceV=0;
            sequenceC++;
            if(sequenceC==3){
                return false;
            }
        }
        
        //e 와 o 를 제외한 연속된 2개 단어면 false
        if(i!=0){
            if(st[i]==st[i-1]&&st[i]!='e'&&st[i]!='o'){
                return false;
            }
        }
    }
    if(vowels==0) return false;//모음이 0개면 false
    
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    while(true){
        string st;
        cin>>st;
        if(st=="end") break;
        
        if(isAcceptable(st)){
            cout<<"<"<<st<<"> is acceptable.\n";
        }
        else{
            cout<<"<"<<st<<"> is not acceptable.\n";
        }
       
    }
}

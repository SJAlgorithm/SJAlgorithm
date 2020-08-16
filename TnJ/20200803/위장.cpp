#include<bits/stdc++.h>
using namespace std;
map<string,int> k;

int solution(vector<vector<string>> ct) {
    int ans = 1;
    for(int i=0; i<ct.size(); i++){
        k[ct[i][1]]++;
    }
    for(auto val : k){
        ans *= val.second+1;
    }
    return ans-1;
}
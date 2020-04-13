// <암호코드> BOJ_2011
// DP, 구현
// 구현 너무 힘들었음... ㅠㅠ

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000;

string code;
int dp[5010]={0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>code;
    // i==0 
    int c1 = code[0]-'0';
    if(!c1) { cout<<"0"; return 0;}
    else dp[0] = 1;
    // i==1
    int c2 = code[1]-'0';
    if(!c2) {
        if(c1<=2) dp[1] = 1;
        else {cout<<"0"; return 0;}
    }
    else { // c2 == 1~9
        if(c1==1) dp[1] = 2;
        else if(c1==2 && c2<=6) dp[1] = 2;
        else dp[1] = 1;
    }
    for(int i=2; i<code.size(); i++){
        int cur = code[i]-'0';
        int pre = code[i-1]-'0';
        if(!cur){
            if(pre==0 || pre>=3) { cout<<"0"; return 0;}
            dp[i] = dp[i-2] % MOD;
            continue;
        }
        if(!pre) dp[i]= dp[i-1] % MOD;
        else if(pre > 2) dp[i] = dp[i-1] % MOD;
        else if(cur>6 && pre==2) dp[i] = dp[i-1] % MOD;
        else dp[i] = dp[i-1]%MOD + dp[i-2]%MOD;
    }
    cout<<dp[code.size()-1]%MOD;
}
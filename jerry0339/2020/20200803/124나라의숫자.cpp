#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[22]{};
int presum[22]{};
string solution(int n) {
    if(n==1) return "1";
    string ans = "";
    dp[0]=1; presum[0]=dp[0];
    for(int i=1; i<19; i++) dp[i] = dp[i-1]*3;
    for(int i=1; i<19; i++){
        presum[i] = presum[i-1] + dp[i];
    }
    int id;
    for(int i=1; i<19; i++){
        if(presum[i]>n) {
            n -= presum[i-1];
            id = i;
            break;
        }
    }
    
    while(id--){
        int t = n%3;
        if(t==0) ans += "1";
        else if(t==1) ans += "2";
        else if(t==2) ans += "4";
        n /= 3;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
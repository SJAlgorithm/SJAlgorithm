#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int MOD = 10007;

int N,M,H;
int dp[51][1001]{};
vector<int> v[51];

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M>>H;
    string s;
    getline(cin, s);
    for(int i=1; i<=N; i++) {
        getline(cin, s, '\n');
        stringstream ss(s);
        string token;
        while(getline(ss, token, ' ')) {
            v[i].push_back(stoi(token));
        }
        sort(v[i].begin(), v[i].end());
    }
    
    dp[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int k=0; k<=H; k++) dp[i][k] = dp[i-1][k];
        for(int j=0; j<v[i].size(); j++){
            for(int k=v[i][j]; k<=H; k++){            
                dp[i][k] = (dp[i][k] + dp[i-1][k-v[i][j]])%MOD;
            }
        }
    }

    cout<<dp[N][H];
}
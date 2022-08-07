#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a(1);
vector<int> b(1);
int dp[1002][1002]{};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,t;
    cin>>N>>M;
    for(int i=0; i<N; i++) {cin>>t; a.push_back(t);}
    for(int i=0; i<M; i++) {cin>>t; b.push_back(t);}
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(N>M) {
        swap(a,b);
        swap(N,M);
    }
    
    for(int i=1; i<=N; i++){
        dp[i][i] = dp[i-1][i-1] + abs(a[i]-b[i]);

        for(int j=i+1; j<=M; j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(a[i]-b[j]));
        }
    }

    cout<<dp[N][M];
}
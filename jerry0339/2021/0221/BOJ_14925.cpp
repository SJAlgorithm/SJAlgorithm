#include<iostream>
#include<algorithm>
using namespace std;

int m[1010][1010]{};
int dp[1010][1010]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;

    int max_=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>m[i][j];
            if(m[i][j]==0){
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                max_ = max(max_, dp[i][j]);
            }
        }
    }
    cout<<max_;
}
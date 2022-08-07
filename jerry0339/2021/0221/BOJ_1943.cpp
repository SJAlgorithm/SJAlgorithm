// 총합이 k일때, 주어진 동전으로 k/2를 만들 수 있다면, 주어진 동전으로 반드시 k를 반으로 나눌 수 있음
// (= k/2원을 2세트 만들 수 있음)

#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

vector<pii> v;
bool dp[200010]{};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int N,a,b;
    while(cin>>N){
        v.clear();
        memset(dp,0,sizeof(dp));
        int sum=0, max_=0, min_=100000, half;
        for(int i=0; i<N; i++) {
            cin>>a>>b;
            v.push_back({a,b});
            sum += a*b;
            max_ = max(max_, a);
            min_ = min(min_, a);
        }

        if(sum%2) {cout<<0<<'\n'; continue;}
        half = sum/2;
        if(max_ > half) {cout<<0<<'\n'; continue;}

        sort(v.begin(), v.end(), [&](pii a, pii b) -> bool {
            return a.xx > b.xx;            
        });

        dp[0] = true;
        for(auto val : v){
            for(int i=half; i>=0; i--){
                if(!dp[i]) continue;
                for(int j=1; j<=val.yy; j++){
                    dp[i+(j*val.xx)] = true;
                }
                if(dp[half]) goto exit;
            }
        }

    exit:
        if(dp[half]) cout<<1<<'\n';
        else cout<<0<<'\n';
    }

}
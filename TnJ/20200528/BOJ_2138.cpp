// <전구와 스위치> - BOJ_2138
// Greedy
// 시뮬레이션 문제가 아님...!!
// n번째 전구가 눌렸는지 안눌렸는지에 따라 전구에 상태가 정해지므로,
// n-1번째까지 전구가 0 or 1인지 정해져 있다면, n-1번전구를 바꿀 수 있는전구는 n번째 전구 밖에 없다는 아이디어로 문제를 풀 수 있음.
// 따라서 그리디하게 n-1까지 전구 스위치 상태를 선택하고, n번째의 전구가 정답과 다르다면 -1를 출력.

#include<bits/stdc++.h>
using namespace std;

int N;
string t1;
string t2;
int st1[100001]{};
int st2[100001]{};
int ans[100001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>t1>>t2;

    for(int i=0; i<N; i++){
        if(t1[i]=='0') {st1[i]=0; st2[i]=0;}
        else {st1[i]=1; st2[i]=1;}
    }

    for(int i=0; i<N; i++){
        if(t2[i]=='0') ans[i]=0;
        else ans[i]=1;
    }
    st2[0] = !st2[0];
    st2[1] = !st1[1];

    int sum1=0;
    int sum2=1;
    for(int i=1; i<N-1; i++){
        if(st1[i-1]!=ans[i-1]) {
            st1[i] = !st1[i]; 
            st1[i+1] = !st1[i+1];    
            sum1++;
        }
        if(st2[i-1]!=ans[i-1]) {
            st2[i] = !st2[i]; 
            st2[i+1] = !st2[i+1];
            sum2++;
        }
    }
    if(st1[N-2]!=ans[N-2]) {
        st1[N-1] = !st1[N-1];
        sum1++;
    }
    if(st2[N-2]!=ans[N-2]) {
        st2[N-1] = !st2[N-1];
        sum2++;
    }
    int min_ = 1e6;
    if(st1[N-1]==ans[N-1]) min_ = sum1;
    if(st2[N-1]==ans[N-1]) min_ = min(min_,sum2);

    if(!min_) cout<<"-1";
    else cout<<min_;
}
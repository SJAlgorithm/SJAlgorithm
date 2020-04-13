// <구슬게임> - BOJ_2600
// DP
// 풀이방법은 하단참고

#include<bits/stdc++.h>
using namespace std;

bool dp[501][501]={0,}; 
vector<pair<int,int>> v;
int b1,b2,b3; // 1<=b1<b2<b3<=30
int k1,k2;    // 1<=k1,k2<=500
int mk1, mk2 = 0;
int T = 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>b1>>b2>>b3;
    while(T--){
        cin>>k1>>k2;
        v.push_back({k1,k2});
        mk1 = max(mk1,k1);
        mk2 = max(mk2,k2);
    }
    for(int i=0; i<=mk1; i++){ 
        for(int j=0; j<=mk2; j++){
            if(i-b1 >= 0 && !dp[i-b1][j]){dp[i][j]=1; continue;}
            if(j-b1 >= 0 && !dp[i][j-b1]){dp[i][j]=1; continue;}
            if(i-b2 >= 0 && !dp[i-b2][j]){dp[i][j]=1; continue;}
            if(j-b2 >= 0 && !dp[i][j-b2]){dp[i][j]=1; continue;}
            if(i-b3 >= 0 && !dp[i-b3][j]){dp[i][j]=1; continue;}
            if(j-b3 >= 0 && !dp[i][j-b3]){dp[i][j]=1; continue;}
        }
    }
    for(auto val : v) dp[val.first][val.second] ? cout<<'A'<<'\n': cout<<'B'<<'\n';
}


// dp[i][j] : (k1,k2)가 (i,j)일때 뽑는 사람이 승자로 결정될 수 있는지 판단.
// (0,0) 일경우 A가 무조건 패배(A부터 뽑기때문)이므로 바텀업으로 DP함

/* 예를들어, 
(b1,b2,b3) = (1,3,4)
(k1,k2) = (4,1)일 경우
k1에서 3을 가져갈 경우 (1,1)이 되고 이때 뽑는 사람은 무조건 지게 되어 있음
즉, (i,j) = (4,1)일때 뽑는사람이 뽑을 수 있는 6가지 방법중 위처럼 하나라도 이길 수 있는 방법이 존재하면 이길 수 있음
위경우는 (1,1)일때 뽑는사람이 무조건 패배라는것을 DP를 통해 알고 있으므로
dp[4][1] = true;가 될 수 있는것임.
따라서 메모이제이션 방식은 바텀업으로 현재(i,j)에서 i또는 j에 b1,b2,b3를 뺏을때(6가지)의 인덱스가
false(무조건 지는 상황)라면, dp[i][j] = true가 될 수 있는것임.
*/
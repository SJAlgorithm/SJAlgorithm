// <저울> - BOJ_2437
// 그리디 , 어려움....

// 풀이방법 : Strong Induction으로 풀이를 고안해 내야 함(귀납법).
//           또는 아이디어를 생각해 내고 모순을 찾아봐야 함(귀류법).
// 자세한 풀이방법은 검색 ㄱㄱ

#include<bits/stdc++.h>
using namespace std;

int m[1001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];
    sort(m,m+N);
    int sum=0;
    for(int i=0; i<N; i++){
        if(sum+1 < m[i]) {cout<<sum+1; return 0;}
        else sum+=m[i];
    }

    cout<<sum+1;
}
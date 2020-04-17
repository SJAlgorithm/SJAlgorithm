// <점프 점프> BOJ_11060
// 누적점프값(jump배열) 초기화를 -1로 했다가 오류 엄청고침...
// 길찾기 최소값 문제들 INF값 적극활용하자 !!

#include<bits/stdc++.h>
using namespace std;

int N;
int m[1010];
vector<int> jump(1001,1001); // INF 설정

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) cin>>m[i];
    jump[1]=0;
    for(int i=1; i<N; i++) {
        for(int j=1; j<=m[i]; j++){
            if(i+j>N) break;
            jump[i+j] = jump[i+j] <= jump[i] ? jump[i+j] : jump[i]+1;
        }
    }
    if(jump[N]==1001) cout<<-1;
    else cout<<jump[N];
}
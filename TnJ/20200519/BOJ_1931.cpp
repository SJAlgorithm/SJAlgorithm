// <회의실 배정> - BOJ_1931
// 그리디 - 끝나는시간(end)을 기준으로 오름차순정렬, end가 같을 경우 st가 빠른경우 우선
// st까지 정렬하는 이유 : (2,2)처럼 st==end인 경우 (2,2), (1,2)순으로 탐색하면 2가지 이지만 st를 정렬안하면 1이 나옴.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define all(v) (v).begin(), (v).end()

int N;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        int st,end; cin>>st>>end;
        v.push_back(make_pair(end,st));
    }
    sort(all(v));

    int c=v[0].xx;
    int cnt=1;
    for(int i=1; i<N; i++){
        if(c <= v[i].yy) {
            cnt++;
            c = v[i].xx;
        }
    }
    cout<<cnt;
}
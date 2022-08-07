// 2020/5/19에 정한 문제는 아니지만 1931과 비슷한 문제라 풀어봄.

// <강의실 배정> - BOJ_11000
// 그리디
// <회의실 배정>-BOJ_1931과 비슷한 문제 같지만 다른 방법의 그리디 접근임!!!
// BOJ_1931의 풀이를 이용하여 배정한 강의 삭제하는 식으로 코드짜면 tle맞음-> O(n^2)풀이임
// 아래의 pq와 for문 참고.

/*
(0 6), (6 10), (12 14)
(1 4), (5 7), (8 11)
(2 13)
(3 5) (5 9) (12 12)
(3 8) (8 12)

pq에 위와같이 들어가서 최종으로 pq에 남아 있는 값은
11, 12, 12, 13, 14가 됨
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
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
        v.push_back(make_pair(st,end));
    }
    sort(all(v));

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].yy);

    for(int i=1; i<N; i++){
        if(pq.top()<=v[i].xx){
            pq.pop();
            pq.push(v[i].yy);
        } else{
            pq.push(v[i].yy);
        }
    }

    cout<<pq.size();
}


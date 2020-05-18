// <숨바꼭질3> - BOJ_13549
// 다익스트라

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 100000;

int N,K;
bool vi[MAX+1] = {0,};

int dijkstra(int start){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start}); // dis,pos

    while(!pq.empty()){
        int cdis = pq.top().first;
        int cpos = pq.top().second;
        pq.pop();
        cout<<cdis<<' '<<cpos<<'\n';
        if(cpos==K) return cdis;

        // 다익스트라를 사용하더라도 *2를 큐에 제일먼저 안넣어주면, 
        // N(start지점)==1 일때 1+1해서 pos==2에 dis==1이 저장되어 오류가 생김. 
        // 원래는 1*2해서 pos==2에 dis==0이 되어야 함
        if(cpos*2<=MAX && !vi[cpos*2]){ 
            pq.push({cdis,cpos*2});
            vi[cpos*2] = true;
        }
        if(cpos+1<=MAX && !vi[cpos+1]){
            pq.push({cdis+1,cpos+1});
            vi[cpos+1] = true;
        }
        if(cpos-1>=0 && !vi[cpos-1]){
            pq.push({cdis+1,cpos-1});
            vi[cpos-1] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    cout<<dijkstra(N);
}
// <돌다리> - BOJ_12761
// BFS

#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
bool vi[100001]={0,};
int a,b,n,m;

int bfs(int start){
    queue<pair<int,int>> q; // <position, count>
    q.push(make_pair(start,0));
    vi[start] = true;
    while(!q.empty()){
        int curPos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(m==curPos) return cnt;
        if(curPos-1>=0 && !vi[curPos-1]) { // -1
            q.push(make_pair(curPos-1,cnt+1));
            vi[curPos-1]=true;
        }
        if(curPos+1<=MAX && !vi[curPos+1]) { // +1
            q.push(make_pair(curPos+1,cnt+1));
            vi[curPos+1]=true;
        }
        if(curPos-a>=0 && !vi[curPos-a]) { // -a
            q.push(make_pair(curPos-a,cnt+1));
            vi[curPos-a]=true;
        }
        if(curPos+a<=MAX && !vi[curPos+a]) { // +a
            q.push(make_pair(curPos+a,cnt+1));
            vi[curPos+a]=true;
        }
        if(curPos-b>=0 && !vi[curPos-b]) { // -b
            q.push(make_pair(curPos-b,cnt+1));
            vi[curPos-b]=true;
        }
        if(curPos+b<=MAX && !vi[curPos+b]) { // +b
            q.push(make_pair(curPos+b,cnt+1));
            vi[curPos+b]=true;
        }
        if(curPos*a<=MAX && !vi[curPos*a]) { // *a
            q.push(make_pair(curPos*a,cnt+1));
            vi[curPos*a]=true;
        }
        if(curPos*b<=MAX && !vi[curPos*b]) { // *b
            q.push(make_pair(curPos*b,cnt+1));
            vi[curPos*b]=true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>n>>m;
    cout<<bfs(n);
}
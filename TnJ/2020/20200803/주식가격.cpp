#include <string>
#include <vector>
#include <queue>
#define xx first
#define yy second
typedef std::pair<int,int> pii;
using namespace std;

vector<int> solution(vector<int> prc) {
    int sz = prc.size();
    vector<int> ans(sz);
    priority_queue<pii> pq;
    pq.push({prc[0],0});
    
    for(int i=1; i<sz-1; i++){
        while(!pq.empty()){
            if(pq.top().xx <= prc[i]) break;
            int ni = pq.top().yy;
            pq.pop();
            ans[ni] = i-ni;
        }
        pq.push({prc[i],i});
    }
    while(!pq.empty()){
        int np = pq.top().xx;
        int ni = pq.top().yy;
        pq.pop();
        ans[ni] = sz-1-ni;
    }
    return ans;
}

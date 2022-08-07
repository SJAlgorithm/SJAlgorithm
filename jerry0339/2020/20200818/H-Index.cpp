#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> ct) {
    int max_=0, min_=10000;
    sort(ct.begin(), ct.end());
    int t = ct.size();
    
    int s = 0, e = t;
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        int cnt = 0;
        for (int i = 0; i < t; i++) if(ct[i] >= mid) cnt++;
        
        if (cnt>=mid) s = mid + 1;
        else          e = mid - 1;   
    }
    return e;
}
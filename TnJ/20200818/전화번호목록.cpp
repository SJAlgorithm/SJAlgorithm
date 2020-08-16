#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> pb) {
    bool ans = true;
    int sz = pb.size();
    sort(pb.begin(),pb.end());
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            ans = false;
            for(int k=0; k<pb[i].size(); k++){
                if(pb[i][k] != pb[j][k]) {ans = true; break;}
            }
            if(ans==false) return ans;
        }
    }
    return true;
}
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    
    sort(rocks.begin(),rocks.end());
    
    int left=0;
    int right=1000000000;
    
    while(left<=right){
        int mid=(left+right)/2;
        int sum=0;
        int st=0;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]-st<mid){
                sum++;
            }
            else{
                st=rocks[i];
            }
        }
        
        if(sum>n){
            right=mid-1;
        }
        else{
            answer=mid;
            left=mid+1;
        }
    }
    return answer;
}

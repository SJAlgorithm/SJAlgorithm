#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    vector<long long> temp;
    sort(times.begin(),times.end());
    long long left=1;
    long long right=n*(long long)times[times.size()-1];
    
    
    while(left<=right){
        long long sum=0;
        long long middle=(left+right)/2;
        for(int i=0;i<times.size();i++){
            sum+=middle/times[i];
        }
        
        if(sum<n){
            left=middle+1;
        }
        else{
            if(middle<=right) answer=middle;
            right=middle-1;
        }
    }
    return answer;
}

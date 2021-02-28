#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long one[300001];
long long two[300001];
int n;


long long total(long long middleLow){
    int middle=n/2;
    int left=middle-1;
    int right=middle+1;
    long long sum=abs(one[middle]-middleLow)+abs(two[middle]-middleLow);
    
    while(left>=0&&right<n){
        middleLow++;
        sum+=abs(one[left]-middleLow)+abs(two[left]-middleLow)+abs(one[right]-middleLow)+abs(two[right]-middleLow);
        left--;
        right++;
    }
    return sum;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>one[i];
    }
    for(int i=0;i<n;i++){
        cin>>two[i];
    }
    
    //중앙의 높이에 대한 이분탐색
    long long left=0;
    long long right=1000000000000-n/2;//중앙의 최대높이
    long long Min=total(left);
    long long Max=total(right);
    while(left<=right){
        long long middle=(left+right)/2;
        if(Min<Max){
            right=middle-1;
            if(right<0) break;
            Max=total(right);
        }
        else{
            left=middle+1;
            Min=total(left);
        }
    }
    cout << min(Min,Max) << endl;

	return 0;
}

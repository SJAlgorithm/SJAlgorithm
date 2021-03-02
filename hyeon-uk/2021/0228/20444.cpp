#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n,k;
    cin>>n>>k;
    
    long long left,right,middle;
    left=0;
    right=n;
    bool flag=false;
    while(left<=right){
        //middle= 가로로 자른 횟수
        //n-middle=세로로 자른 횟수
        middle=(left+right)/2;
        
        //세로로 n-middle번,가로 middle 번 자른뒤 나오는 조각
        long long s= (n-middle+1)*(middle+1);
        
        if(s>k){
            right=middle-1;
        }
        else if(s<k){
            left=middle+1;
        }
        else{
            flag=true;
            break;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
	return 0;
}

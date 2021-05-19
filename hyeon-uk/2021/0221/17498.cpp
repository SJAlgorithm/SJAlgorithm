#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const long long INF = 1e12;
int n,m,k;
long long dp[200001];
long long arr[200001];
//x= position/m , y=position%m


long long abc(int position){
    //범위 벗어나면 최솟값 리턴
    if(position>=n*m){
        return -INF;
    }
    
    
    //position으로 i,j 설정
    int i=position/m;
    int j=position%m;
    
    
    //마지막줄이면 끝이니 0리턴
    if(i==n-1){
        return 0;
    }
    
    
    //만약 값이 있으면 그 값 리턴
    if(dp[position]!=-INF) return dp[position];
    
    
    //움직일 수 있는 범위들을 재귀로 돌려서 최댓값 저장
    for(int x=i+1;x<=i+k;x++){
        for(int y=j-k;y<=j+k;y++){
            if((x<n&&x>=0)&&(y<m&&y>=0)&&(abs(x-i)+abs(y-j)<=k)){
                dp[position]=max(dp[position],arr[position]*arr[x*m+y]+abc(x*m+y));
            }
        }
    }
    
    return dp[position];
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<200001;i++){
        dp[i]=-INF;
    }
    
    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i*m+j];
        }
    }
    
    long long mx=-INF;
    
    for(int i=0;i<m;i++){
        mx=max(mx,abc(i));
    }
    
    cout<<mx;
    
	return 0;
}
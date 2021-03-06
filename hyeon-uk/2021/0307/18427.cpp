#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n,m,h;
vector<int> v[51];
int dp[51][1001]={0};//dp[i][j]=k, i명이 k를 만들수 있는 경우의수 k


//수행시간 O(n*m*h)
void solve(){
    //0을 만드는 경우는 모두 1개씩
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=h;j++){
            for(int k=0;k<v[i].size();k++){
                //사람이 한명 더 줄은 상태의 j-v[i][k]높이의 경우의수를  모두 더해준다.
                if(j-v[i][k]>=0){
                    dp[i][j]+=dp[i-1][j-v[i][k]];
                    dp[i][j]%=10007;
                }
            }
            //i번째 사람이 안들어갔을때도 완성이 될 수 있으므로 더해준다
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=10007;
        }
    }
    
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>h;
    cin.ignore(1);
    for(int i=1;i<=n;i++){
        string data;
        getline(cin,data);
        int temp=0;
        for(int j=0;j<data.size();j++){
            if(data[j]==' '){
                v[i].push_back(temp);
                temp=0;
            }
            else{
                temp=temp*10+(data[j]-'0');
            }
        }
        if(temp!=0)    v[i].push_back(temp);
    }
    
    solve();
    cout<<dp[n][h]<<"\n";
	return 0;
}
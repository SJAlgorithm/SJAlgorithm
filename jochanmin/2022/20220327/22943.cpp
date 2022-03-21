#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;


int k,m;
bool prime[100001];
bool sumPrime[100001];
bool sumPrimeSame[100001];
bool sameAtom(int num){
	bool arr[10]={false};
	while(num){
		if(!arr[num%10]) arr[num%10]=true;
		else return true;
		num/=10;
	}
	return false;
}
bool check(int num){
    if(!sumPrime[num]) return false;
    if(sameAtom(num)) return false;
    while(num%m==0){
        num/=m;
    }
    if(!sumPrimeSame[num]) return false;
    return true;
}
int main(){
  cin>>k>>m;
  vector<int> primeList;
  memset(prime,true,sizeof(prime));
  prime[0]=false;prime[1]=false;
  for(int i=2;i*i<100000;i++){
      if(prime[i]){
          for(int j=i*i;j<100000;j+=i) prime[j]=false;
      }
  }
  for(int i=2;i<100000;i++){
      if(prime[i]) primeList.push_back(i);
  }
  for(int i=0;i<primeList.size();i++){
      for(int j=i+1;j<primeList.size();j++){
          if(primeList[i]+primeList[j]<100000)
           sumPrime[primeList[i]+primeList[j]]=true;
      }
  }
  for(int i=0;i<primeList.size();i++){
      for(int j=i;j<primeList.size();j++){
          if((long long)primeList[i]*primeList[j]<100000)
           sumPrimeSame[primeList[i]*primeList[j]]=true;
      }
  }
  int count =0;
  if(k==1){
      for(int i=1;i<10;i++){
          if(check(i)) count++;
      }
  }else{
      for(int i=(int)pow(10,k-1);i<(int)pow(10,k);i++){
          if(check(i)) count++;
      }
  }
  cout<<count;
}
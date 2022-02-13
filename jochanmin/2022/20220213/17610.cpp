#include <cstdio>
#include <algorithm>
using namespace std;
int arr[14];
int n,s;
bool visit[200000*13+12];
void go(int weight,int depth){
	if(depth==n){
		if(weight>0) visit[weight]=true;
		return;
	}
	go(weight+arr[depth],depth+1);
	go(weight-arr[depth],depth+1);
	go(weight,depth+1);
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		s+=arr[i];
	}
	go(0,0);
	int cnt=0;
	for(int i=1;i<=s;i++){
		if(!visit[i]) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
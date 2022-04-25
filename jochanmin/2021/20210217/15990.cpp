#include <cstdio>
using namespace std;
#define mod 1000000009

long long arr[100001][3];
int main() {
	int t;
	scanf("%d",&t);
	arr[1][0]=1;
	arr[2][1]=1;
	arr[3][0]=1;arr[3][1]=1;arr[3][2]=1;
	for(int i=4;i<=100000;i++){
		arr[i][0]=(long long)(arr[i-1][1]+arr[i-1][2])%mod;
		arr[i][1]=(long long)(arr[i-2][0]+arr[i-2][2])%mod;
		arr[i][2]=(long long)(arr[i-3][0]+arr[i-3][1])%mod;
	}
	while(t--){
		int num;scanf("%d",&num);
		printf("%lld\n",(arr[num][0]+arr[num][1]+arr[num][2])%mod);
	}
	return 0;
}
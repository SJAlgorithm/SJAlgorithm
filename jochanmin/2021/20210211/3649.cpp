#include <cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;


int main() {
	int x;
	int n;
	while(scanf("%lld",&x)==1){
		ll arr[1000001];
		x*=10000000;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		bool flag=false;
		for(int i=0;i<n-1;i++){
			ll c=*lower_bound(arr+i+1,arr+n,x-arr[i]);
			if(c==x-arr[i]){
				printf("yes %lld %lld\n",arr[i],c);
				flag=true;
				break;
			}
		}
		if(!flag)
		 printf("danger\n");
	}
	return 0;
}
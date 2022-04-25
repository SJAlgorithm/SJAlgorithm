#include <cstdio>
#include<queue>
using namespace std;

int main() {
	int n;
	int arr[100001];
	scanf("%d",&n);
	int sum=0;
	int two=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		two+=arr[i]/2;
		sum+=arr[i];
	}
	if(sum%3==0 && two>=sum/3){
		printf("YES");
	}else printf("NO");
	
	return 0;
}
#include <cstdio>
#include<cmath>
using namespace std;
bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
int main() {
	int n;
	scanf("%d",&n);
	int count=0;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		if(isPrime(num)) count++;
	}
	printf("%d",count);
	return 0;
}
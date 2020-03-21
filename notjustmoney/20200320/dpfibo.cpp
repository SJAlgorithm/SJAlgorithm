#include <bits/stdc++.h>
using namespace std;

long long m[100] = {0};
long long fibo(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	if(m[n] != 0) {
		return m[n];	
	} else {
		m[n] = fibo(n-1) + fibo(n-2);
		return m[n];	
	}
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%lld\n", fibo(N));
	return 0;	
}

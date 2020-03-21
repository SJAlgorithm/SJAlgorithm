#include <bits/stdc++.h>
using namespace std;

long long rfibo(int n) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	return rfibo(n-1)+rfibo(n-2);
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", rfibo(N));
	
	return 0;	
}

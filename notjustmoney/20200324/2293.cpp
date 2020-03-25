#include <bits/stdc++.h>
using namespace std;
int s[10001];
int c[101];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", c+i);
		if(c[i] > k) {
			n--;
			i--;	
		}
	}
	s[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = c[i]; j <= k; j++) {
			s[j] += s[j-c[i]];	
		}
	}
	printf("%d\n", s[k]);
		
	return 0;	
}

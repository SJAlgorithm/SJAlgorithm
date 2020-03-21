#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	int count = 2;
	scanf("%d", &N);
	
	char C1, C2;
	for(int i = 0; i < N; i++) {
		getchar();
		scanf("%c", &C1);
		if(i == 0) C2 = C1;
		if(C1 != C2){
			count++;
			C2 = C1;	
		}
	}
	printf("%d\n", count);
	
	return 0;	
}

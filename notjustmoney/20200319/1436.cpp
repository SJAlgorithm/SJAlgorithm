	#include <bits/stdc++.h>
	using namespace std;
	
	bool isDeath(int n) {
		int count=0;
		while(n) {
			if(n%1000==666){
				return true;
			}
			n /= 10;
		}
		return false;
	}
	
	int main() {
		
		int N;
	
		scanf("%d", &N);
		int num = 1;
		int count = 0;
		while(1) {
			if(isDeath(num)) {
				count++;
				if(count == N) {
					printf("%d\n", num);
					return 0;
				}
			}
			num++;
		}
	}

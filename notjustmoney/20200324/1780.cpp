#include <bits/stdc++.h>
using namespace std;

char arr[2187][2187];
int cnt[3] = {0};
int N;
int check(int x, int y, int l) {
	int c = arr[x][y];
	for(int i = 0; i < l; i++)
	for(int j = 0; j < l; j++) 
		if(c != arr[x+i][y+j]) return -2;		
			
	return c;
}

void dq(int x, int y, int l) {
	int ck = check(x, y, l);
	if(ck != -2) {
		cnt[ck+1]++;
		return;
	} else {
		dq(x, y, l/3);
		dq(x+l/3, y, l/3);
		dq(x+l*2/3, y, l/3);
		dq(x, y+l/3, l/3);
		dq(x+l/3, y+l/3, l/3);
		dq(x+l*2/3, y+l/3, l/3);
		dq(x, y+l*2/3, l/3);
		dq(x+l/3, y+l*2/3, l/3);
		dq(x+l*2/3, y+l*2/3, l/3);		
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++) 
		scanf("%d", &arr[i][j]);
	dq(0, 0, N);
	for(int i = 0; i < 3; i++) 
		printf("%d\n", cnt[i]);	
	return 0;	
}

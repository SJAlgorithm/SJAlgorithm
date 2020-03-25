#include <bits/stdc++.h>
using namespace std;
int arr[128][128];
int wcnt;
int bcnt;
int N;	// 2, 4, 8, 16, 32, 64, 128
int cnt;
int check(int idx1, int idx2, int l){
	int c = arr[idx1][idx2];
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) {
			if(arr[idx1+i][idx2+j] != c) 
				return -1;
		}
	}
	return c;
}

void inc(int c) {
	if(c == 0) wcnt++;
	if(c == 1) bcnt++;	
}

// 정사각형의 크기를 인자로 색을 확인 후, 분할정복 
void dq(int idx1, int idx2, int l) {
	int tmp = check(idx1, idx2, l);
	if(tmp != -1) {
		inc(tmp);
		return;
	} else {
		dq(idx1, idx2, l/2);
		dq(idx1, idx2+l/2, l/2);
		dq(idx1+l/2, idx2, l/2);
		dq(idx1+l/2, idx2+l/2, l/2);
	}
	
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) 
	for(int j = 0; j < N; j++)
		scanf("%d", &arr[i][j]);
	dq(0, 0, N);
	printf("%d\n%d\n", wcnt, bcnt);
	return 0;	
}

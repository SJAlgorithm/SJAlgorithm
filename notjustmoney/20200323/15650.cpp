#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];

void dfs(int num, int cnt) {
	if(cnt == M) {
		for(int i = 0; i < M; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	if(num > N) return;
	arr[cnt++] = num;
	dfs(num+1, cnt);
	cnt--;
	dfs(num+1, cnt);
}

int main() {
	scanf("%d %d", &N, &M);
	dfs(1, 0);	
	
	return 0;	
}

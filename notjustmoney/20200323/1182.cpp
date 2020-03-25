#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[20] = {0};
int cnt = 0, sum = 0;

void dfs(int idx) {
	if(idx == N) return;
	if(sum + arr[idx] == S) cnt++;
	
	dfs(idx+1);
	
	sum += arr[idx];
	dfs(idx+1);
	
	sum -= arr[idx];
}

int main() {
	scanf("%d %d", &N, &S);
	for(int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0);
	printf("%d\n", cnt);
	return 0;	
}

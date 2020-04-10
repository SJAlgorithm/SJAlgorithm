// "기업투자", https://www.acmicpc.net/problem/2662
// writen in C++
// 2020. 03. 28
// notjustmoney
#include <bits/stdc++.h>
using namespace std;

int a[301][21];
int m[301][21];
int N, M, x;

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%*d");
		for(int j = 1; j <= M; j++) scanf("%d", &a[i][j]);
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			m[i][j-1] < a[i][j] ? m[i][j] = a[i][j] : m[i][j] = m[i][j-1];
			for(int k = 1; k < i; k++) {
				m[i][j] < m[i][j-1] + a[i-k][j] ? m[i][j] = m[i][j-1] + a[i-k][j] : m[i][j] = m[i][j];	
			}
		}
	}
	
	printf("%d\n", m[N][M]);
	return 0;
}

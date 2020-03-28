// "≈‰∏∂≈‰", https://www.acmicpc.net/problem/7576
// writen in C++
// 2020. 03. 28
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int g[1000][1000];
int main() {
	int dcnt = 0;
	int day = 0;
	int M, N;
	queue<pair<int, int>> q;
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &g[i][j]);
			if(g[i][j] == 1) {
				q.push(make_pair(i, j));
				dcnt++;
			}
		}
	}
	int dy[4] = {0, 1, 0, -1};
	int dx[4] = {1, 0, -1, 0};
	bool v[1000][1000] = { false };
	while(!q.empty()){
		int cnt = 0;
		bool flag = false;
		for(int k = 0; k < dcnt; k++){
			pair<int, int> s = q.front(); q.pop(); 
			v[s.first][s.second] = true;
			for(int i = 0; i < 4; i++) {
				int y = s.first + dy[i];
				int x = s.second + dx[i];
				if(y >= 0 && y < N && x >= 0 && x < M && g[y][x] == 0 && !v[y][x]) {
					g[y][x] = 1;
					q.push(make_pair(y, x));
					cnt++;
					flag = true;
				}
			}
		}
		dcnt = cnt;
		if(flag) day++;
	}
	for(int i = 0; i < N; i++)
	for(int j = 0; j < M; j++) 
	if(!v[i][j] && g[i][j] == 0) {
		printf("-1\n");
		return 0;	
	}
	
	printf("%d\n", day);
	return 0;
}

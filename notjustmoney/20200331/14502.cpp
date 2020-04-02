#include <bits/stdc++.h>
using namespace std;
int a[8][8];
int b[8][8];
int N, M;
int total, wall, virus, result;
vector<pair<int, int> > q;

void copy(int(*a)[8], int(*b)[8]) {
	for(int i = 0; i < N; i++) 
	for(int j = 0; j < M; j++)
		b[i][j] = a[i][j];	
}

void bfs() {
	int r[8][8];
	copy(b, r);
	int dy[4] = {0, 1, 0, -1};
	int dx[4] = {1, 0, -1, 0};
	int cnt = total-(wall+virus+3);
	queue<pair<int, int> > cq;
	for(int i = 0; i < virus; i++) cq.push(q[i]);
	while(!cq.empty()){
		pair<int, int> s = cq.front(); cq.pop();
		for(int i = 0; i < 4; i++) {
			int y = s.first + dy[i];
			int x = s.second + dx[i];
			if(y >= 0 && y < N && x >= 0 && x < M && r[y][x] == 0) {
				r[y][x] = 2;
				cq.push(make_pair(y, x));
				cnt--;
			}	
		}
	}
	result = max(result, cnt);
}

void create_wall(int wcnt) {
	if(wcnt == 3) {
		bfs();
		return;
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(b[i][j] == 0) {
				b[i][j] = 1;
				create_wall(wcnt+1);
				b[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	total = N*M;
	wall = virus = result = 0;
	for(int i = 0; i < N; i++)
	for(int j = 0; j < M; j++)
	{
		scanf("%d", &a[i][j]);
		if(a[i][j] == 1) wall++;
		else if(a[i][j] == 2) {
			virus++;
			q.push_back(make_pair(i, j));
		}
	}
	for(int i = 0; i < N; i++) 
	for(int j = 0; j < M; j++) {
		if(a[i][j] == 0) {
			copy(a, b);	
			b[i][j] = 1;
			create_wall(1);
			b[i][j] = 0;
		}
	}
	printf("%d\n", result);
	return 0;	
}

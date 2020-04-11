// "½ºµµÄí", https://www.acmicpc.net/problem/2580
// writen in C++
// 2020. 04.10
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int sudoku[10][10];
vector<pair<int, int> > v;

void print_sudoku() {
	for(int i=1; i<=9; i++) {
		for(int j=1; j<=9; j++)
			printf("%d ", sudoku[i][j]);
		printf("\n");				
	}
}

bool chk(int n, int y, int x) {
	// raw check
	for(int i=1; i<=9; i++) {
		if(sudoku[y][i] == n) return false;
	}
	
	// col check
	for(int i=1; i<=9; i++) {
		if(sudoku[i][x] == n) return false;
	}
	
	// box check
	int cy, cx;
	if(y <= 3) cy = 1;
	else if(y <= 6) cy = 4;
	else cy = 7;
	
	if(x <= 3) cx = 1;
	else if(x <= 6) cx = 4;
	else cx = 7;
	
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(sudoku[cy+i][cx+j] == n) return false;
		}
	}
	
	return true;
}

void dfs(int pos) {
	vector<int> st;
	for(int i=1; i<=9; i++)
		if(chk(i, v[pos].first, v[pos].second)) {
			if(pos == v.size()-1) {
				sudoku[v[pos].first][v[pos].second] = i;
				print_sudoku();
				exit(0);	
			}
			st.push_back(i);
		}

	while(st.size()) {
		int n = st.back(); st.pop_back();
		sudoku[v[pos].first][v[pos].second] = n;
		dfs(pos+1);	
		sudoku[v[pos].first][v[pos].second] = 0;
	}
}

int main() {
	for(int i=1; i<=9; i++) 
	for(int j=1; j<=9; j++) {
		scanf("%d", &sudoku[i][j]);
		if(!sudoku[i][j]) v.push_back({ i, j });
	}
	dfs(0);
	return 0;
}

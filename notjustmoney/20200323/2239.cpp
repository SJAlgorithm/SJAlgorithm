#include <bits/stdc++.h>
using namespace std;
int b[9][9];

bool isZero() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(b[i][j] == 0) return true;	
		}
	}
	return true;
}

// 가로세로를 검사해 n이라는 값을 넣는 것이 가능한지 반환 
bool isPossible(int n) {
	
}

void dfs() {
	if(!isZero()) return;
	
}

void print_board() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			printf("%d", b[i][j]);	
		}
		printf("\n");
	}
}

int main() {
	char input[10];
	for(int i = 0; i < 9; i++){
		scanf("%s", input);
		for(int j = 0; j < 9; j++) {
			b[i][j] = (input[j]-'0');	
		}
	}
	print_board();

	return 0;	
}

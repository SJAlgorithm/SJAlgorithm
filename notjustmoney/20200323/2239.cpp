#include <bits/stdc++.h>
using namespace std;
int b[9][9];
int main() {
	char input[10];
	for(int i = 0; i < 9; i++){
		scanf("%s", input);
		for(int j = 0; j < 9; j++) {
			b[i][j] = (input[j]-'0');	
		}
	}
	
	for(int i = 0; i < 9; i++) printf("%d", b[1][i]);

	return 0;	
}

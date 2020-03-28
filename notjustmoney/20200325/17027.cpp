#include <bits/stdc++.h>
using namespace std;
bool shell[4] = {0};
int max_point;
int main() {
	int N;
	scanf("%d", &N);
	
	int input[100][3];
	for(int i = 0; i < N; i++)
		scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) shell[j] = false;
		int count = 0;
		shell[i] = true;
		
		for(int i =0; i < N; i++) {
			bool tmp = shell[input[i][0]];
			shell[input[i][0]] = shell[input[i][1]];
			shell[input[i][1]] = tmp;
			if(shell[input[i][2]]) count++;
		}
		if(max_point < count) max_point = count;
	}
	printf("%d\n", max_point);
	
	return 0;	
}

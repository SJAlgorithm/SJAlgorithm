#include <bits/stdc++.h>
using namespace std;

char word[50002];
int m[26][50001] = {0};
int a1[26] = {0};
int a2[26] = {0};
int A, B, C, D;
bool isPossible() {
	if(B-A != D-A) return false;
	
	int i;
	
	for(i=0; i<26; i++){
		
	}
	return true;
}
int main() {
	scanf("%s", word+1);
	for(int i=1; !word[i]; i++){
		
	}

	int Q;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		if(isPossible()) printf("DA\n");
		else printf("NE\n");	
	}
	
}

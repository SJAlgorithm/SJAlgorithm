#include <bits/stdc++.h>
using namespace std;

char S[50001];
int A,B,C,D;
bool isPossible() {
	int a1[26] = {0};
	int a2[26] = {0};
	int i;
	for(i=A; i<=B; i++) {
		a1[S[i]-'a']++;
	}
	for(i=C; i<=D; i++) {
		a2[S[i]-'a']++;
	}
	for(i=0; i<26; i++) {
		if(a2[i] < a1[i]) return false;
	}
	return true;
}

int main() {
	scanf("%s", S+1);
	
	int Q;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++) {
		scanf("%d %d %d %d", &A, &B, &C, &D);
		if(isPossible()) printf("DA\n");
		else printf("NE\n");
	}
	
	return 0;
}

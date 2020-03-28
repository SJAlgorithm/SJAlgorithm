// "암호 만들기", https://www.acmicpc.net/problem/1759
// writen in C++
// 2020. 03. 28
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
int L, C;
string a;
char p[15];
char moum[5] = {'a', 'e', 'i', 'o', 'u'};
bool isMoum(char ch){
	for(int i = 0; i < 5; i++) {
		if(ch == moum[i]) return true;	
	}
	return false;
}
void dfs(int idx, int cnt, int acnt) {
	if(cnt == L) {
		p[cnt] = '\0';
		if(cnt-acnt >= 2 && acnt >= 1) printf("%s\n", p);
		return;
	}
	if(idx >= C) return;
	
	if(isMoum(a[idx])) acnt++;
	p[cnt++] = a[idx];
	dfs(idx+1, cnt, acnt);
	if(isMoum(a[idx])) acnt--;
	dfs(idx+1, --cnt, acnt);
}
int main() {
	scanf("%d %d", &L, &C);
	getchar();
	getline(cin, a);
	a.erase(remove(a.begin(), a.end(), ' '), a.end());
	sort(a.begin(), a.end());
	dfs(0, 0, 0);
	return 0;	
}

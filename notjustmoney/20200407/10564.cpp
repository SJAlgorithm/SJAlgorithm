#include <bits/stdc++.h>
using namespace std;
int n, m, s[10], dp[5054];
void go(int prev, int point) {
	for(int i=0; i<m; i++) {
		int pal=prev+point+s[i];
		if(pal>n || dp[pal]>(point+s[i])) continue;
		dp[pal] = point+s[i]; 
		go(pal, point+s[i]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++) {
			scanf("%d", s+i);
			dp[s[i]]=s[i];
		}
		for(int i=0; i<m; i++) 
			go(s[i], s[i]);
		if(dp[n]) printf("%d\n", dp[n]);
		else printf("-1\n");
	}
	return 0;
}

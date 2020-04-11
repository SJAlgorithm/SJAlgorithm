#include <bits/stdc++.h>
using namespace std;
int n, m, s[10], dp[5054], ans;
void go(int total_pushup, int total_point) {
	if(total_pushup ==n ) {
		if(dp[total_pushup] < total_point) {
			ans = total_point;
			dp[total_pushup] = total_point;
		}
		return;	
	}
	for(int i=0; i<m; i++) {
		int new_pushup=total_pushup+(total_point+s[i]);
		if(new_pushup>n || dp[new_pushup]>(total_point+s[i])) { continue; }
		int ex=dp[new_pushup];
		dp[new_pushup] = total_point+s[i]; 
		go(new_pushup, total_point+s[i]);
		if(new_pushup != n) dp[new_pushup]=ex;
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
		}
		for(int i=0; i<m; i++) {
			go(s[i], s[i]);
		}
		if(dp[n]) printf("%d\n", dp[n]);
		else printf("-1\n");
	}
	return 0;
}

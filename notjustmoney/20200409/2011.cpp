// "암호코드", https://www.acmicpc.net/problem/2011
// writen in C++
// 2020. 04.09 
// notjustmoney
#include <bits/stdc++.h>
using namespace std;
char str[5054];
int a[5054];
int dp[5054];
int len;
int main() {
	scanf("%s", str);
	for(int i=0; str[i]; i++) {
		a[i+1] = (str[i]-'0');
		len++;	
	}

	dp[0] = 1;
	for(int i=1; i<=len; i++) {
		if(a[i] >= 1 && a[i] <= 9)
			dp[i] = (dp[i]+dp[i-1])%1000000;
		if(i==1) continue;
		int num = (a[i-1])*10+(a[i]);
		if(num<=26 && num>=10)
			dp[i] = (dp[i]+dp[i-2])%1000000;
	}
	printf("%d\n", dp[len]);	
	return 0;	
}

// "ºÐÇØÇÕ", https://www.acmicpc.net/problem/2231
// writen in C++
// 2020. 03. 18.
// notjustmoney

#include <bits/stdc++.h>
using namespace std;
int self_sum(int n){
	int sum=0;
	
	while(n) {
		sum += n%10;
		n /= 10;
	}
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; // 1<=N<=1000000
	int tmp, i;
		
	cin >> N;
	for(i = 1; i <= N; i++) {
		tmp = i + self_sum(i);
		if(tmp == N || i == N){
			break;	
		}
	}	
	
	if(i == N) {
		cout << 0 << '\n';
	} else {
		cout << i << '\n';
	}
	
	return 0;	
}

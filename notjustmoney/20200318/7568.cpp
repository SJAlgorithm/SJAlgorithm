// "µ¢Ä¡", https://www.acmicpc.net/problem/7568
// writen in C++
// 2020. 03. 19.
// notjustmoney
#include <bits/stdc++.h>
using namespace std;

typedef struct pinfo{
	int weight;
	int tall;
	int place;	
}_pinfo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<_pinfo> a(N);
	for(int i = 0; i < N; i++) {
		cin >> a[i].weight;
		cin >> a[i].tall;	
	}
	
	int place = 1;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(a[j].weight > a[i].weight && a[j].tall > a[i].tall) {
				place++;	
			} 
		}	
		a[i].place = place;
		place = 1;
	}
	
	for(int i = 0; i < N; i++) {
		cout << a[i].place << ' ';	
	}
	cout << '\n';
	return 0;	
}

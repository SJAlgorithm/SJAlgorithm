// "µ¢Ä¡", https://www.acmicpc.net/problem/7568
// writen in C++
// 2020. 03. 19.
// notjustmoney
#include <bits/stdc++.h>
#include <string>

using namespace std;

typedef struct pokemon{
	int num;
	string name;
}_pokemon;

bool cmp(_pokemon& p1, _pokemon& p2) {
	int pos = 0; 
	while (p1.name[pos] != '\0' && p2.name[pos] != '\0') {
  		if (p1.name[pos] > p2.name[pos]){
  	 		return false;
  	 	} else if (p1.name[pos] < p2.name[pos]) { 
	 		return true;
	 	}
		pos++; 
	} 
	return p1.name[pos] == '\0' ? true : false; 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N;
	cin >> M;
	
	vector<_pokemon> sa(N);
	vector<string> a(N+1);
	for(int i = 0; i < N; i++) {
		sa[i].num = i+1;
		cin >> sa[i].name;
		a[i+1] = sa[i].name;
	}
	
	sort(sa.begin(), sa.end(), cmp); 
	
	string input;
	int start, end, mid;
	int idx;
	for(int i = 0; i < M; i++) {
		cin >> input;
		if(input[0] >= '1' && input[0] <= '9') {
			idx = stoi(input);
			cout << a[idx] << '\n';
		} else {
			start = 0;
			end = N-1;
			while(end-start >= 0) {
				mid = (start + end)/2;
				if(sa[mid].name.compare(input)==0){
					cout << sa[mid].num << '\n';
					break;	
				} else if(sa[mid].name.compare(input) > 0){
					end = mid-1;
				} else {
					start = mid+1;	
				}
			}
		}
	}
	
	return 0;
}

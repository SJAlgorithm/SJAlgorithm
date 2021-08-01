#include <iostream>
#include<algorithm>
using namespace std;

int n, d, k, c;
int belt[3000001] = { 0 };
int check[3001] = { 0 };
int kind = 0, result = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> d >> k >> c;
	check[c]++;//쿠폰
	kind++;//쿠폰으로 인한 종류 1개 증가

	for (int i = 0; i < n; i++) {
		cin >> belt[i];
		//처음K개에 대해서 종류를 체크
		if (i < k) {
			if (check[belt[i]]==0) {//처음만나는 음식이면 kind 1 증가
				kind++;
			}
			check[belt[i]]++;
		}
	}
	result = kind;

	for (int i = 0; i < n; i++) {
		//값 갱신
		result = max(result, kind);

		//종류 바꾸기
		int tail = belt[i];//현재 꼬리
		int head = belt[(i+k)%n];//다음 머리가 될 음식

		//현재 꼬리를 자른뒤, 종류 갱신
		check[tail]--;
		if (!check[tail]) {
			kind--;
		}

		//다음 머리를 추가한뒤, 종류 갱신
		check[head]++;
		if (check[head] == 1) {
			kind++;
		}
	}
	cout << result << "\n";

	

	return 0;
}
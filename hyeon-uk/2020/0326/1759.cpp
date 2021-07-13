#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

char arr[15];
int check[15] = { 0 };
int l, c;
int mo=0, ja=0;
char result[15];

bool ismo(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int num,int cnt) {
	if (mo >= 1 && ja >= 2 && cnt == l) {
		for (int i = 0; i < l; i++) {
			cout << result[i];
		}
		cout << "\n";
		return;
	}

	for (int i = num; i < c; i++) {
		if (check[i] == false) {
			check[i] = true;
			result[cnt] = arr[i];
			if (ismo(arr[i])) {
				mo++;
			}
			else {
				ja++;
			}
			dfs(i+1,cnt + 1);
			if (ismo(arr[i])) {
				mo--;
			}
			else {
				ja--;
			}
			check[i] = false;
		}
	}
}

int main() {
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	sort(arr+0, arr+c);
	dfs(0,0);
	return 0;
}
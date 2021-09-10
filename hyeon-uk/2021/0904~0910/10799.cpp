#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string str;
	cin >> str;

	int pipes = 0;
	int pieces = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			pipes++;
		}
		else {
			//레이져일때
			if (str[i - 1] == '(') {
				pipes--;
				pieces += pipes;
			}
			//파이프 끝자락일때
			else {
				pipes--;
				pieces++;
			}
		}
	}
	cout << pieces;

	return 0;
}
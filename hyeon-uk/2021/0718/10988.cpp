#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;

	bool flag = true;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] != str[len - 1 - i]) {
			flag = false;
			break;
		}
	}
	cout << flag;
	return 0;
}
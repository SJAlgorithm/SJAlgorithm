#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int alpha[26] = { 0 };
		for (int j = a - 1; j < b; j++) {
			alpha[str[j] - 'a']++;
		}

		bool flag = true;

		for (int j = c - 1; j < d; j++) {
			if (--alpha[str[j] - 'a'] < 0) {
				flag = false;
				cout << "NE\n";
				break;
			}
		}
		if (flag) cout << "DA\n";
	}
}

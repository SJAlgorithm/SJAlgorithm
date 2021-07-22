#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

string a, b;
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << a << " & " << b << " are NOT anagrams.\n";
		}
		else {
			int cntA[26] = { 0 };
			int cntB[26] = { 0 };
			bool flag = true;
			int len = a.size();
			for (int j = 0; j < len; j++) {
				cntA[a[j] - 'a']++;
				cntB[b[j] - 'a']++;
			}
			for (int j = 0; j < 26; j++) {
				if (cntA[j] != cntB[j]) {
					flag = false;
					break;
				}
			}


			if (flag) {
				cout << a << " & " << b << " are anagrams.\n";
			}
			else {
				cout << a << " & " << b << " are NOT anagrams.\n";
			}
		}
	}
	return 0;
}
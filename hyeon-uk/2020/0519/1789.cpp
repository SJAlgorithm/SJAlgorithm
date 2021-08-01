#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long s;
	cin >> s;
	int cnt = 0;
	for (int i = 1; s - i >= 0; i++) {
		s -= i;
		cnt++;
	}
	cout << cnt;
	return 0;
}
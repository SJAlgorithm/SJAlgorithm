#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int t,n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		priority_queue<int> ma,mi;
		int middle;
		cout << (n + 1) / 2 << "\n";
		for (int i = 1; i <= n; i++) {
			int data;
			cin >> data;
			if (i == 1) middle = data;
			else {
				if (data > middle) {
					mi.push(-data);
				}
				else {
					ma.push(data);
				}
			}
			if (i % 2 == 1) {
				if (mi.size() > ma.size()) {
					ma.push(middle);
				}
				else {
					mi.push(-middle);
				}
				if (mi.size() > ma.size()) {
					middle = -mi.top();
					mi.pop();
				}
				else {
					middle = ma.top();
					ma.pop();
				}
				cout << middle << " ";
				if (i % 10 == 0) cout << "\n";
			}
		}
		cout << "\n";
	}
}

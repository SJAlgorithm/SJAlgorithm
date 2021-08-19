#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

bool is_prime[1000001] = { 0 };
bool is_ok[1000001] = { 0 };
bool is_false[1000001] = { 0 };
map<int,bool> visited;
bool sogen(int n) {
	while (n != 1) {
		if (is_ok[n]) {
			return true;
		}
		if (is_false[n]) {
			return false;
		}
		if (visited[n]) {
			for (auto k : visited) {
				is_false[k.first] =true;
			}
			return false;
		}
		visited[n] = true;
		int total = 0;
		while (n) {
			total += ((n % 10)*(n % 10));
			n /= 10;
		}
		n = total;
	}
	for (auto k : visited) {
		is_ok[k.first] = true;
	}
	return true;
}

void solve(int n) {
	for (int i = 2; i <= n; i++) is_prime[i] = true;

	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			visited.clear();
			if (sogen(i)) {
				cout << i << "\n";
			}
			for (int j = i + i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	solve(n);
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int flag = 1;
	int sum;
	for (int i = 1; i <= n; i++) {
		sum = i;
		int temp = i;
		while (temp > 0) {
			sum+=temp%10;
			temp /= 10;
		}
		if (n == sum) {
			cout << i;
			flag = -1;
			break;
		}
	}
	if (flag == 1) {
		cout << 0;
	}
}

#include<iostream>
#include <algorithm>
#include<memory.h>
using namespace std;

int n, m;
int tree[1000000];

int main() {
	long long sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		sum += tree[i];
	}

	long long left = 0;
	long long right = sum;
	long long answer = -1;
	while (left <= right) {
		long long middle = (left + right) >> 1;
		long long temp = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > middle) {
				temp += (tree[i] - middle);
			}
		}
		if (temp < m) {
			right = middle-1;
		}
		else {
			answer = middle;
			left = middle+1;
		}
	}
	cout << answer;

	return 0;
}
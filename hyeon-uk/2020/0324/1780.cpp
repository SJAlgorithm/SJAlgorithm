#include<iostream>

using namespace std;

int one = 0;
int zero = 0;
int mn = 0;
void divid(int **a, int n, int stx, int sty) {
	bool flag = true;
	int color = a[stx][sty];

	if (n == 1) {
		if (color == 1) one++;
		else if(color==0) zero++;
		else mn++;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color != a[stx + i][sty + j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	if (!flag) {
		divid(a, n / 3, stx, sty);
		divid(a, n / 3, stx+n / 3, sty);
		divid(a, n / 3, stx, sty+ n / 3);
		divid(a, n / 3, stx+ n / 3, sty+ n / 3);
		divid(a, n / 3, stx+ n / 3+ n / 3, sty+ n / 3);
		divid(a, n / 3, stx+ n / 3, sty+ n / 3+ n / 3);
		divid(a, n / 3, stx+ n / 3+ n / 3, sty+ n / 3+ n / 3);
		divid(a, n / 3, stx+ n / 3+ n / 3, sty);
		divid(a, n / 3, stx, sty+ n / 3+ n / 3);
	}
	else {
		if (color == 1) one++;
		else if(color==0) zero++;
		else mn++;
	}
	return;
}


int main() {
	int n;
	cin >> n;
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	divid(arr, n, 0, 0);
	cout<<mn<<'\n' << zero << '\n' << one;
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
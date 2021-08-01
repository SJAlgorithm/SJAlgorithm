#include<iostream>

using namespace std;

int blue = 0;
int white = 0;

void divid(int **a, int n,int stx,int sty) {
	bool flag = true;
	int color = a[stx][sty];

	if (n == 1) {
		if (color == 1) blue++;
		else white++;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color != a[stx+i][sty+j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	if (!flag) {
		divid(a, n / 2,stx,sty);
		divid(a, n / 2,stx,sty+n/2);
		divid(a, n / 2,stx+n/2,sty);
		divid(a, n / 2,stx+n/2,sty+n/2);
	}
	else {
		if (color == 1) blue++;
		else white++;
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
	divid(arr, n,0,0);
	cout << white << '\n' << blue;
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
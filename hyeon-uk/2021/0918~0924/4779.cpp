#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

string init(int n) {
	string str = "";
	for (int i = 0; i < n; i++) str += "-";
	return str;
}

void make_blank(string& str, int st, int end) {
	for (int i = st; i <= end; i++) {
		str[i] = ' ';
	}
}

void func(string& str,int st,int end) {
	if (st==end) {
		return;
	}
	int size = (end-st+1) / 3;

	func(str, st, st+size - 1);
	make_blank(str, st+size,end-size);
	func(str, end - size + 1, end);

}

int main() {
	int n;
	while (cin >> n) {
		n = pow(3, n);
		string str = init(n);
		func(str, 0, n - 1);
		cout << str << "\n";
	}
	return 0;
}